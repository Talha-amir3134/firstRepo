#include <iostream>
using namespace std;

struct node
{
    int value;
    node* link;
};


class linklist
{
private:
    node* plist;
public:
    linklist()
    {
        plist = NULL;
    }

    void addNode(int val)
    {
        node* newNode = new node;
        newNode->value = val;
        newNode->link = NULL;
        if(plist == NULL)
        {
            plist = newNode;
        }
        else
        {
            node* slider = plist;
            while(slider->link != NULL)
            {
                slider = slider->link;
            }
            slider->link = newNode;
        }
    }


    void addBefore(int target, int value)
    {
        node* newNode = new node;
        newNode->value = value;
        if (target == plist->value)
        {
            newNode->link = plist;
            plist = newNode;
        }
        else
        {
            node* newNode  = new node;
            newNode->value = value;
            node* prev;
            node* slider;
            while(slider != NULL && slider->value != target)
            {
                prev = slider;
                slider = slider->link;
            }
            prev->link = newNode;
            newNode->link = slider;
        }

    }

    void addAfter(int target, int value)
    {
        node* newNode  = new node;
        newNode->value = value;
        node* prev;
        node* slider;
        while(slider != NULL && slider->value != target)
        {
            prev = slider;
            slider = slider->link;
        }
        slider = slider->link;
        prev->link = newNode;
        newNode->link = slider;
    }


    void deleteNode(int trgt)
    {
        node* prev;
        node* target;
        node* slider = plist;
        while (slider->value != trgt && slider->link != NULL)
        {
            prev = slider;
            slider = slider->link;
        }
        target = slider;
        slider = slider->link;
        delete target;
        prev->link = slider;
    }

    void showList()
    {
        node* slider = plist;
        while (slider != NULL) {
            cout << slider->value << endl;
            slider = slider->link;
        }
    }
};


int main()
{
    linklist myList;
    myList.addNode(5);
    myList.addNode(10);
    myList.addNode(17);
    myList.addBefore(17,18);
    myList.showList();
}