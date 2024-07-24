
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Creating a Message Class
class Message {
public:
    string sender;
    string receiver;
    string content;
    static map<pair<string, string>, vector<string>> messages;  // Static member to store messages between users

    Message() {}

// to initialize a message
    Message(string sender, string receiver, string content) {
        this->sender = sender;
        this->receiver = receiver;
        this->content = content;
    }


    // to display the message
    void displayMessage() const {
        // Displaying the individual messages
        cout << "From: " << sender << " To: " << receiver << " Content: " << content << endl;
    }

    void storeMessage() {
        // Storing the messages
        messages[{sender, receiver}].push_back(content);
    }
};

map<pair<string, string>, vector<string>> Message::messages;

class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {}

    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }

// to display user details

    void displayUser() const {
        cout << "Name: " << firstName << " " << lastName << ", Age: " << age << ", Gender: " << gender << endl;
    }
};

class SocialGroup {
    string groupName;
    vector<pair<string, string>> messages;
    vector<string> members;

public:
    SocialGroup() {}
  // to initialize a social group with a name
    SocialGroup(string groupName) {
        this->groupName = groupName;
    }


    // to add a member to the group
    void addMember(const string& userName) {
        // Check if the member is already in the group
        if (std::find(members.begin(), members.end(), userName) != members.end()) {
            cout << "Member " << userName << " is already in the group." << endl;
        } else {
            members.push_back(userName);
            cout << "Member " << userName << " added to the group " << groupName << "." << endl;
        }
    }

  // to add a message to the group
    void sendMessage(const string& userName, const string& content) {
        messages.push_back({userName, content});
    }

  // to display group details
    void displayGroup() const {
        cout << "Group: " << groupName << "\nMembers:\n";
        for (const auto& member : members) {
            cout << member << "\n";
        }
    }
};

class SocialNetwork {
    map<string, User> mapUserName;
    map<string, set<string>> friends;

public:
// to add a user to the network
    void addUser(const string& userName, const User& user) {
        if (mapUserName.find(userName) == mapUserName.end()) {
            mapUserName[userName] = user;
            cout << "User " << userName << " added successfully." << endl;
        } else {
            cout << "UserName " << userName << " already taken." << endl;
        }
    }

    // Method to make two users friends
    void makeThemFriend(const string& userName1, const string& userName2) {
        friends[userName1].insert(userName2);
        friends[userName2].insert(userName1);
    }

    // to display all users
    void displayAllUser() const {
        for (const auto& i : mapUserName) {
            cout << "UserName: " << i.first << " ";
            i.second.displayUser();
        }
    }

    // to display all friendships
    void displayAllFriendships() const {
        for (const auto& i : friends) {
            cout << i.first << ":\n";
            const set<string>& friends = i.second;
            for (const auto& j : friends) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    SocialNetwork network;
    string userName1, userName2, firstName, lastName, gender;
    int age;

    // Take user input for the first user
    cout << "Enter details for user 1:\n";
    cout << "UserName: ";
    cin >> userName1;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Age: ";
    cin >> age;
    cout << "Gender: ";
    cin >> gender;
    User user1(firstName, lastName, age, gender);
    network.addUser(userName1, user1);

    // Take user input for the second user
    cout << "Enter details for user 2:\n";
    cout << "UserName: ";
    cin >> userName2;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Age: ";
    cin >> age;
    cout << "Gender: ";
    cin >> gender;
    User user2(firstName, lastName, age, gender);
    network.addUser(userName2, user2);

    // Make the two users friends
    network.makeThemFriend(userName1, userName2);

    // Chat Box Functionality
    Message message(userName1, userName2, "Hey, please wake up early tomorrow");
    message.displayMessage();
    message.storeMessage();

    // Social Groups Functionality
    SocialGroup group1("Goa trip");
    group1.addMember(userName1);

    // Display all users
    network.displayAllUser();

    // Display all friendships
    network.displayAllFriendships();

    return 0;
}
