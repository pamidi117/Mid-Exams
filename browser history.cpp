#include <iostream>
#include <string>
using namespace std;

// Node definition for the linked list
struct Webpage {
    string url;
    Webpage* next;

    Webpage(const string& link) : url(link), next(nullptr) {}
};

// Function to add a new webpage to the linked list
Webpage* addWebpage(Webpage* head, const string& url) {
    Webpage* newWebpage = new Webpage(url);
    newWebpage->next = head;
    return newWebpage;
}

// Function to display the browser history
void displayHistory(Webpage* head) {
    cout << "Browser History:" << endl;
    Webpage* current = head;
    while (current != nullptr) {
        cout << current->url << endl;
        current = current->next;
    }
}

int main() {
    int numPages;
    cout << "Enter the number of webpages visited: ";
    cin >> numPages;
    cin.ignore(); // Ignore newline character after reading numPages

    // Create an empty linked list for browser history
    Webpage* history = nullptr;

    // Input URLs visited by the user
    for (int i = 0; i < numPages; ++i) {
        string url;
        cout << "Enter URL visited " << i + 1 << ": ";
        getline(cin, url);
        history = addWebpage(history, url);
    }

    // Display the browser history
    displayHistory(history);

    // Free memory by deleting the linked list
    while (history != nullptr) {
        Webpage* temp = history;
        history = history->next;
        delete temp;
    }

    return 0;
}
