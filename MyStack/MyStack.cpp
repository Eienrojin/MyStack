#include <iostream>
#include <cstring>

using namespace std;

struct MyStack
{
    int info;
    MyStack* next;
} *beginStack;

MyStack* inStack(MyStack* p, int in)
{
    MyStack* t = new MyStack;
    t->info = in;
    t->next = p;
    return t;
}

void viewStack(MyStack* p)
{
    int iter = 1;
    MyStack* t = p;
    while (t != NULL)
    {
        cout << iter << ". " << t->info << endl;
        t = t->next;
        iter++;
    }
}

void dellStack(MyStack** p)
{
    MyStack* t;

    while (*p != NULL)
    {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}

void sortInfo(MyStack* p) 
{
    MyStack* t = NULL, *t1; 
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next)
        {
            if (t1->info > t1->next->info)
            {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        }
        
        t = t1;
    } while (p->next != t);
}

int calculateAverage(MyStack* p)
{
    MyStack* t = NULL, * t1;

    t1 = p;
    int count = 0;
    int sum = 0;

    do {
        sum += t1->info;
        count++;
        t1 = t1->next;
    } while (t1->next != NULL);

    t = t1;
    count++;
    sum += t->info;

    cout << "Average = " << sum / count << endl;

    return sum / count;
}

void replaceEvenToAvrg(MyStack* p, int average)
{
    MyStack* t = NULL, * t1;

    t1 = p;

    do {
        if (t1->info % 2 == 0)
        {
            t1->info = average;
        }
        t1 = t1->next;
    } while (t1->next != NULL);

    t = t1;

    if (t->info % 2 == 0)
        t->info = average;
}

int main()
{
    int i, in, n, answer, average;

    while (true)
    {
        cout << "1. Create\n"
            << "2. Add\n"
            << "3. View\n"
            << "4. Delete\n"
            << "5. Sort\n"
            << "6. Calculate average + replace even\n"
            << "10. Exit" << endl;

        cin >> answer;

        switch (answer)
        {
        default:
            cout << "Unknown choice" << endl;
            break;
        case 1: case 2:
            if (answer == 1 && beginStack != NULL)
            {
                cout << "You must clear the memory before create a new Stack";
                break;
            }
            
            cout << "Input a count of nums: ";
            cin >> n;

            for (int i = 1; i <= n; i++)
            {
                in = -10 + rand() % 50;

                beginStack = inStack(beginStack, in);
            }

            if (answer == 1)
            {
                cout << "Create " << n << endl;
            }
            else
            {
                cout << "Add " << n << endl;
            }
            break;

        case 3:
            if (!beginStack)
            {
                cout << "Stack is empty" << endl;
                break;
            }

            cout << "------------------------" << endl;

            viewStack(beginStack);

            cout << "------------------------" << endl;
            break;

        case 4:
            dellStack(&beginStack);

            cout << "Memory has cleaned" << endl;
            break;

        case 5:
            sortInfo(beginStack);
            break;

        case 6:
            if (!beginStack)
            {
                cout << "Stack is empty" << endl;
                break;
            }

            average = calculateAverage(beginStack);
            replaceEvenToAvrg(beginStack, average);
            break;

        case 10:
            dellStack(&beginStack);
            return 0;
        }

        system("pause");
        system("cls");
    }
}