Description: Browser history is a feature found in web browsers that maintains a record of webpages visited by the user 
during a browsing session.It allows users to navigate back and forth through their browsing history, revisit previously 
visited webpages, and track their browsing activity over time.

Context : In web browsers, managing browsing history efficiently is essential for providing users with a seamless browsing 
experience and facilitating easy navigation between webpages.Linked lists offer several advantages in this context due to
their dynamic nature and efficient memory utilization.By using linked lists to represent browser history, the browser can 
easily, track and manage the sequence of webpages visited by the user, enabling quick access to previous pages and supporting 
functionalities such as forward and backward navigation.

Utilization :
 
 Dynamic History Management :
Linked lists are well - suited for dynamically managing browser history.Each webpage visited by the user is represented as a node 
in a linked list, with each node containing information about the URL of the webpage and a pointer to the next webpage.As the user 
navigates through different webpages, the browsers, dynamically updates the linked list by adding new nodes for each visited webpage, 
maintaining the chronological order of the browsing history.

Efficient Navigation Operations :
When a user navigates backward or forward through their browsing history, the browser utilizes linked lists to facilitate efficient 
navigation operations.By traversing the linked list in reverse or forward direction, the browser can quickly retrieve the URLs of 
previously visited webpages, allowing users to revisit specific pages with minimal latency.Linked lists enable seamless backward 
and forward navigation, enhancing user experience and usability.

Memory Efficiency :
Linked lists provide efficient memory utilization for managing browser history.Unlike fixed - size arrays or matrices, linked lists
allocate memory dynamically as needed, accommodating varying numbers of webpages visited by the user.This memory efficiency is 
particularly advantageous in scenarios where the size of the browsing history may vary dynamically based on user behavior, ensuring 
optimal resource utilization and performance.

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
