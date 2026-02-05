#include <bits/stdc++.h>
using namespace std;

int token = 0, tokens[50], payment_counter = 0;

int main_page();
int menu_order();
void Bill_show(int id[], int q[], int counter);
void Bill_Payment();

int main()
{
    cout << "########################################\n";
    cout << "########################################\n";
    cout << "# Welcome to Cafe Barista by Anshu ^_^ #\n";
    cout << "########################################\n";
    cout << "########################################\n";

    int choice;
    do
    {
        choice = main_page();
        switch (choice)
        {
        case 1:
            menu_order();
            break;
        case 2:
            Bill_Payment();
            break;
        case 3:
            cout << "\nBarista Cafe by Anshu\n\n";
            cout << "This session order received : " << token << endl;
            cout << "This session bill paid      : " << payment_counter << endl;

            if (payment_counter < token)
            {
                cout << "No. of payment remaining: "
                     << token - payment_counter << endl;
            }

            cout << "\nThank You."<<"Have a Great Day and a Great cofee :)\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

int main_page()
{
    int choice;
    cout << "\nQuality food...Serves good.(^_^)\n";
    cout << "1.New Order\n";
    cout << "2.Bill Payment\n";
    cout << "3.Exit\n";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    return choice;
}

void Bill_show(int id[], int q[], int counter)
{
    int sum = 0;

    int costs[8] = {120, 40, 70, 90, 65, 230, 25, 25};
    string items[8] = {
        "  Veg Burger", "Hot Dog", "French Fries","Cold Cofee","Black Cofee",
        "Ice Cream", "Coca-Cola", "Pepsi" };

    cout << "\nYour Bill:\nItem(s)\t\tQuantity\tCost\n";

    for (int i = 0; i < counter; i++)
    {
        cout << i + 1 << ". " << items[id[i] - 1]
             << "\t" << q[i]
             << "\t\t" << q[i] * costs[id[i] - 1] << endl;
        sum += q[i] * costs[id[i] - 1];
    }

    cout << "\nTotal = " << sum << endl;

    if (token < 50)
    {
        token++;
        tokens[token] = sum;
    }
    else
    {
        cout << "Token limit reached!\n";
    }

    cout << "Your token number is " << token
         << ". Use this token while paying the bill.\n";
}

int menu_order()
{
    int id[50], q[50], counter = 0;
    int decision;
    bool ordering = true;

    while (ordering)
    {
        cout << "\nFOOD MENU\n";
        cout << "************************************\n";
        cout << "1.Veg Burger .................120/-\n";
        cout << "2.Hot Dog ................40/-\n";
        cout << "3.Cold Cofee .................120/-\n";
        cout << "4.French Fries ...........90/-\n";
        cout << "5.Ice Cream ..............65/-\n";
        cout << "6.Black Cofee .................180/-\n";
        cout << "7.Coca-Cola ..............25/-\n";
        cout << "8.Pepsi ................25/-\n";
        cout << "************************************\n";

        cout << "Order your dish (Enter 0 to finish):\n";

        while (true)
        {
            cout << "Enter Food ID: ";
            cin >> id[counter];
            if (id[counter] == 0)
                break;

            cout << "Enter Quantity: ";
            cin >> q[counter];
            counter++;
        }

        cout << "\n1.Check Bill\n2.Continue Ordering\n3.Main Menu\n";
        cout << "Enter your choice: ";
        cin >> decision;

        if (decision == 1)
        {
            if (counter > 0)
                Bill_show(id, q, counter);
            else
                cout << "Cannot show bill for empty order.\n";
            ordering = false;
        }
        else if (decision == 2)
        {
            continue;
        }
        else if (decision == 3)
        {
            ordering = false;
        }
    }
    return 0;
}

void Bill_Payment()
{
    int k, cash, choice;
    bool paying = true;

    while (paying)
    {
        cout << "\nEnter your token number: ";
        cin >> k;

        if (k > token || k <= 0 || tokens[k] == 0)
        {
            cout << "Invalid or already paid token number.\n";
            continue;
        }

        payment_counter++;
        cout << "Your Total Bill is = " << tokens[k] << endl;

        do
        {
            cout << "Pay your bill: ";
            cin >> cash;
            if (cash < tokens[k])
            {
                cout << "You have to pay "
                     << tokens[k] - cash << " more.\n";
            }
        } while (cash < tokens[k]);

        cout << "Thanks for your payment. Have a great day and great cofee!\n";
        tokens[k] = 0;

        cout << "1.Pay another bill\n2.Main Menu\nEnter choice: ";
        cin >> choice;

        if (choice == 2)
            paying = false;
    }
}