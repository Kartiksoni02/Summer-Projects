
#include <iostream> // Include standard input-output library
#include <cstdlib> // Include standard library for functions like rand()
#include <cmath> // Include cmath library for mathematical functions
#include <bits/stdc++.h> // Include all standard libraries (for maps, vectors, etc.)
#include <ctime> // Include ctime library for date and time functions
using namespace std;

// PRIORITY
// DUEDATE
// DATA FORMATTING
// TABLE PRINT
// High/Low/Medium   medium , 0 , 1 , 2
// there should be limited categories available
// WORK
// PERSONAL
// REMIND
// BIRTHDAY

class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate; 
    string priority; // LOW MEDIUM HIGH

    // Initialize a Task object
    Task(string description, string category, string priority, string dueDate) {
        this->description = description;
        this->category = category;
        this->dueDate = dueDate;
        this->priority = priority;
        this->completed = false;
    }
};

// To store tasks and categories
stack<pair<Task, int>> undoStack; // Stores task and its original index
vector<Task> NotesAdded;
vector<string> categories = {"Work", "Personal", "Study", "Shopping", "Other"};

// Function to display tasks
void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "Please add some task first to View";
    } else {
        cout << "\nTasks:\n";
        cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << "\n";
        for (int i = 0; i < NotesAdded.size(); i++) {
            cout << i + 1 << ". "
                 << NotesAdded[i].description << " "
                 << NotesAdded[i].category << " "
                 << NotesAdded[i].priority << " "
                 << NotesAdded[i].dueDate << " "
                 << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

// Function to mark a task as completed
void markTaskAsCompleted() {
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded[taskNumber - 1].completed = true;
    } else {
        cout << "Invalid Task Number" << "\n";
    }
}

// Function to delete a task
void deleteTask() {
    // Index of that task
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        Task task = NotesAdded[taskNumber - 1];
        undoStack.push({task, taskNumber - 1}); // Push the task and its index onto the undo stack
        NotesAdded.erase(NotesAdded.begin() + taskNumber - 1); // Erase the task from the list
    } else {
        cout << "Invalid Task Number" << "\n";
    }
}

// Function to undo the last action
void undoLastAction() {
    if (!undoStack.empty()) {
        auto lastAction = undoStack.top();
        undoStack.pop();
        NotesAdded.insert(NotesAdded.begin() + lastAction.second, lastAction.first); // Insert the task back to its original position
    } else {
        cout << "Nothing to Undo" << endl;
    }
}

// Function to filter tasks by category
void filterTaskByCategory() {
    // Display available categories
    cout << "Choose a category to filter by: " << endl;
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << endl;
    }

    // Get user input for category choice
    int categoryChoice;
    cin >> categoryChoice;

    // Check if the category choice is valid or not
    if (categoryChoice > 0 && categoryChoice <= categories.size()) {
        string selectedCategory = categories[categoryChoice - 1];
        cout << "\nTasks in category '" << selectedCategory << "':\n";
        cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << "\n";

        // Display tasks that match the our selected category
        bool found = false;
        for (int i = 0; i < NotesAdded.size(); i++) {
            if (NotesAdded[i].category == selectedCategory) {
                found = true;
                cout << i + 1 << ". "
                     << NotesAdded[i].description << " "
                     << NotesAdded[i].category << " "
                     << NotesAdded[i].priority << " "
                     << NotesAdded[i].dueDate << " "
                     << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
            }
        }
        if (!found) {
            cout << "No tasks found in this category." << endl;
        }
    }
}

// Map to store the leaderboard (player name and score)

// Function to add a task
void addTask() {
    string description;
    string category;
    string priority;

    cout << "Enter the Description\n";

    cin.ignore();
    getline(cin, description);
    auto now = time(nullptr);
    tm* current = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current); // Format the date as YYYY-MM-DD

    string dueDate(buffer);
    cout << "Choose a category: " << endl;

    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << endl;
    }

    int categoryChoice;
    cin >> categoryChoice;

    if (categoryChoice > 0 && categoryChoice <= categories.size()) {
        category = categories[categoryChoice - 1];
    } else {
        cout << "Invalid choice, defaulting to 'Other'" << endl;
        category = "Other";
    }
    cout << "Enter priority (HIGH/MEDIUM/LOW): ";

    cin >> priority;

    Task task(description, category, priority, dueDate);
    NotesAdded.push_back(task);
}

// Function to display the menu and handle user choices
void displayMenu() {
    int choice; // Variable to store the user's menu choice
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Task\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Undo Last Action\n" // Added option for undo
             << "6. Filter Task By Category\n"
             << "7. Exit\n"
             << "Enter your choice: ";

        cin >> choice; // Read the user's choice
        switch (choice) {
            case 1:
                addTask(); // Call addTask function
                break;
            case 2:
                displayTasks(); // Call displayTasks function
                break;
            case 3:
                markTaskAsCompleted(); // Call markTaskAsCompleted function
                break;
            case 4:
                deleteTask(); // Call deleteTask function
                break;
            case 5:
                undoLastAction(); // Call undoLastAction function
                break;
            case 6:
                filterTaskByCategory(); // Call filterTaskByCategory function
                break;
            case 7:
                cout << "Goodbye! Please do the tasks on time";
        }
    } while (choice != 7); // Loop until the user chooses to exit
}

int main() {
    displayMenu(); // Display the menu to the user
    return 0; // End of the program
}
