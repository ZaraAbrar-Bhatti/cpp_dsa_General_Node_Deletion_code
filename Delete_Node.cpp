#include <iostream>
using namespace std;
class Node{
public:
	Node *next;
	int data;
	Node(){
		data = 0;
		next = NULL;
	}
};
class LinkList{
public:
	int addData;
	int value;
	int del_key;
	Node *head;
	Node *tail;
	LinkList(){
		head = NULL;
		tail = NULL;
	}
	void AddNode(int posi){
		cout << "Enter the data you want to store in node = ";
		cin >> posi;
		Node *ptr = new Node;
		ptr->data = posi;
		ptr->next = NULL;
		if (head == NULL){
			head = ptr;
			tail = ptr;
			ptr = NULL;
			delete ptr;
		}
		else{
			tail->next = ptr;
			tail = ptr;
			ptr = NULL;
			delete ptr;
		}
	}
	void delNode(int del_value){
		cout << "Enter '1' if you want to delete head." << endl;
		cout << "Enter '0' if you want to delete tail." << endl;
		cout << "Otherwise enter the value of the node which is just before the node whose value you want to delete :" << endl;
		cin >> del_value;
		Node *ptr = new Node;
		if (del_value == 1){
			ptr = head;
			head = head->next;
			ptr->next = NULL;
			delete ptr;
			cout << "Head node deleted!" << endl;
		}
		else if (del_value == 0){
			for (Node *i = head; i != tail;){
				ptr = i;
				i = i->next;
			}
			ptr->next = NULL;
			tail = ptr;
			ptr = NULL;
			delete ptr;
			cout << "Tail node deleted!" << endl;
		}
		else{
			for (Node *i = head; i != tail;){
				if (i->data == del_value){
					ptr = i->next;
					if (ptr = tail){
						cout << "Kindly choose right option to delete tail of the node!" << endl;
						break;
					}
					i->next = ptr->next;
					ptr->next = NULL;
					cout << "Node having value " << ptr->data << " deleted!" << endl;
					delete ptr;
					break;
				}
				else{
					i = i->next;
				}
			}
		}
	}
	void Display(){
		for (Node *i = head; i != tail;){
			cout << i->data << "->";
			i = i->next;
		}
		cout << tail->data << "->NULL" << endl;
	}
};
int main(){
	LinkList obj;
	obj.AddNode(obj.addData);
	obj.AddNode(obj.addData);
	obj.AddNode(obj.addData);
	obj.AddNode(obj.addData);
	obj.Display();
	cout << endl;
	obj.delNode(obj.del_key);
	obj.Display();
	cout << endl;
	system("pause");
	return 0;
}