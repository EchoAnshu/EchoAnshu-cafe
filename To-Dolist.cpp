#include <bits/stdc++.h>
using namespace std;

vector<string> tasks;

// Load tasks from file
void loadTasks()
{
    ifstream file("tasks.txt");
    string task;
    while (getline(file, task))
    {
        tasks.push_back(task);
    }
}

// Save tasks to file
void saveTasks()
{
    ofstream file("tasks.txt");
    for (string task : tasks)
    {
        file << task << endl;
    }
}

// Show all tasks
void showTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

int main()
{
    loadTasks();
    int choice;

    while (true)
    {
        cout << "\n1. View tasks\n";
        cout << "2. Add task\n";
        cout << "3. Delete task\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            showTasks();
        }
        else if (choice == 2)
        {
            string task;
            cout << "Enter task: ";
            getline(cin, task);
            tasks.push_back(task);
            saveTasks();
        }
        else if (choice == 3)
        {
            showTasks();
            int num;
            cout << "Enter task number: ";
            cin >> num;

            if (num > 0 && num <= tasks.size())
            {
                tasks.erase(tasks.begin() + (num - 1));
                saveTasks();
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
