#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *start, *temp, *ptr, *prevnode, *node;
int p, count = 0;
void insert_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the data";
    cin >> newnode->data;
    cout << "Element inserted" << endl;
    newnode->next = start;
    start = newnode;
}
void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the data";
    cin >> newnode->data;
    cout << "Element inserted" << endl;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    
}
void insert_at_position()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the position";
    cin >> p;
    node = start;
    while (node->next != NULL)
    {
        count++;
        node = node->next;
    }
    if (p > count)
    {
        cout << "Invalid position";
    }
    else
    {
        temp = start;
        cout << "Enter the data";
        cin >> newnode->data;
        for (int i = 2; i < p; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void del_beg()
{
    temp = start;
    start = start->next;
    free(temp);
}
void del_end()
{
    temp = start;
    while (temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }
    free(temp);
    prevnode->next = NULL;
}

void display()
{
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    int choice;
    while (1)
    {
        cout << "1.insert_beg" << endl
             << "2.insert_end" << endl
             << "3.insert_at_position" << endl
             << "4.Delete_beg" << endl
             << "5.Delete_end" << endl
             << "6.display" << endl
             << "7.Exit" << endl;
        cin >> choice;
        switch (choice)
        {

        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_at_position();
            break;
        case 4:
            del_beg();
            break;
        case 5:
            del_end();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);

        default:
            cout << "Wrong choice";
            break;
        }
    }
    return 0;
}