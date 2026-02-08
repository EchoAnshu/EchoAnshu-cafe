#include <bits/stdc++.h>
using namespace std;
//Book structure
class Books{
    public:
        int id;
        string title;
        string author;
        string publisher;
        bool issued;
        
};
int Home_page(){
    int choose;
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add Book\n";
    cout << "2. View Books\n";
    cout << "3. Issued Book\n";
    cout << "4. Return Book\n";
    cout << "5. Delete Book\n";
    cout << "6. Exit\n";
    cin >> choose;
    return choose;
}
// vector <Books> bookshelf;
void loadBooks()
{
    cout<<"Loading books..."<< endl;
}
void saveBooks()
{
    cout << "saving books...";
}
void addBooks()
{
    cout << "adding  books...";
}
void viewBooks()
{
    cout << " viewing books...";
}
void issueBooks()
{
    cout << "issue books...";
}
void returnBooks(){
    cout<<"return books...";
}
void deleteBooks()
{
    cout << "delete books...";
}

int main(){
    //welcome message
    cout << "###################################\n";
    cout << "###################################\n";
    cout << "## Readers always welcomes Here ^_^ ##\n";
    cout << "###################################\n";
    cout << "###################################\n";
    
        // main page(Layout)
        int choice;
    do{
        choice = Home_page();
        switch (choice)
        {
        case 1: addBooks();
            break;
        case 2: viewBooks();
            break;
        case 3: issueBooks();
            break;
        case 4: returnBooks();
            break;
        case 5: deleteBooks();
            break;
        case 6: saveBooks();
            cout << "Saving Data.....!\n";
            break;
        default:
            cout << "Invalid choice ,Please try again...\n";
        }
    }
    while ( choice !=6);
    if (choice == 6)
    {
        cout << "Exiting the program. Goodbye!\n";
    }

    //loadBooks(); //??
    // int choose;
        // do{ 
        // cout << "\n===== Library Management System =====\n";
        // cout << "1. Add Book\n";
        // cout << "2. View Books\n";
        // cout << "3. Issued Book\n";
        // cout << "4. Return Book\n";
        // cout << "5. Delete Book\n";
        // cout << "6. Exit\n";
        // cout << "Enter your choice: ";
        // if (!(cin >> choose))
        // {
        //     cin.clear();            // fix broken cin
        //     cin.ignore(1000, '\n'); // flush garbage
        //     cout << "Enter a NUMBER, genius.\n";
        //     continue; // restart loop
        // }

        // switch (choose)
        // {
        // case 1: addBooks();
        //     break;
        // case 2: viewBooks();
        //     break;
        // case 3: issueBooks();
        //     break;
        // case 4: returnBooks();
        //     break;
        // case 5: deleteBooks();
        //     break;
        // case 6: saveBooks();
        //     cout << "Saving Data.....!\n";
        //     break;
        // default:
        //     cout << "Invalid choice ,Please try again...\n";
        // }}
        // while ( choose !=6);
return 0;
}