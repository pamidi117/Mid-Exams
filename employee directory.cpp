#include <iostream>
#include <string>
using namespace std;

// Node definition for the binary search tree
struct EmployeeNode {
    string name;
    string employeeID;
    EmployeeNode* left;
    EmployeeNode* right;

    EmployeeNode(const string& n, const string& id) : name(n), employeeID(id), left(nullptr), right(nullptr) {}
};

// Function to insert a new employee into the binary search tree
EmployeeNode* insertEmployee(EmployeeNode* root, const string& name, const string& employeeID) {
    if (root == nullptr) {
        return new EmployeeNode(name, employeeID);
    }

    if (name < root->name) {
        root->left = insertEmployee(root->left, name, employeeID);
    }
    else if (name > root->name) {
        root->right = insertEmployee(root->right, name, employeeID);
    }
    else {
        // If employee with the same name already exists, update the employee ID
        root->employeeID = employeeID;
    }

    return root;
}

// Function to search for an employee in the binary search tree
string searchEmployee(EmployeeNode* root, const string& name) {
    if (root == nullptr) {
        return "Employee not found";
    }

    if (name == root->name) {
        return "Employee ID: " + root->employeeID;
    }
    else if (name < root->name) {
        return searchEmployee(root->left, name);
    }
    else {
        return searchEmployee(root->right, name);
    }
}

// Function to delete the entire binary search tree
void deleteEmployeeDirectory(EmployeeNode* root) {
    if (root != nullptr) {
        deleteEmployeeDirectory(root->left);
        deleteEmployeeDirectory(root->right);
        delete root;
    }
}

int main() {
    int numEmployees;
    cout << "Enter the number of employees in the directory: ";
    cin >> numEmployees;
    cin.ignore(); // Ignore newline character after reading numEmployees

    // Create an empty binary search tree for the employee directory
    EmployeeNode* employeeDirectory = nullptr;

    // Input employees' information
    for (int i = 0; i < numEmployees; ++i) {
        string name, employeeID;
        cout << "Enter name for employee " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter employee ID for employee " << i + 1 << ": ";
        getline(cin, employeeID);

        // Insert the employee into the directory
        employeeDirectory = insertEmployee(employeeDirectory, name, employeeID);
    }

    // Search for employees in the directory
    cout << "Search results:" << endl;
    cout << "Enter a name to search: ";
    string searchName;
    getline(cin, searchName);
    cout << searchEmployee(employeeDirectory, searchName) << endl;

    // Delete the entire employee directory to free memory
    deleteEmployeeDirectory(employeeDirectory);

    return 0;
}
