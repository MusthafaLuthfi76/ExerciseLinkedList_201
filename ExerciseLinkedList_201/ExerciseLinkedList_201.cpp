#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //write your answer here

	Node* newNode = new Node();                 //step a.1 & c.1
	cout << "\nMasukkan rollNumber : ";
	cin >> newNode->rollNumber;                 //step a.2 & c.2
	cout << "Masukkan Nama : ";
	cin >> newNode->name;                       //step a.2 & c.2

	if (LAST == NULL) { // List is empty

		newNode->next = newNode; 
		LAST = newNode; 

	}

	else {
		cout << "a) Add at the beginning" << endl;
		cout << "b) Add between two nodes" << endl;
		cout << "c) Add at the end" << endl;
		cout << "Masukkan Pilihan (a-c): ";
		char pilihan;
		cin >> pilihan;

		switch (pilihan) {
		case 'a': {
			newNode->next = LAST->next;         // step a.3 Make the new node point to the successor of LAST
			LAST->next = newNode;               // step a.4 Make the next field of LAST point to the new node
			break;
		}
		case 'b': {
			int rollno;
			cout << "Masukkan roll number setelah angka berapa mau dimasukkan : ";
			cin >> rollno;

			Node* musthafa = LAST->next;		//step b.1
			Node* luthfi = NULL;				//step b.2
			do {								//step b.3
				luthfi = musthafa;				//step b.4
				musthafa = musthafa->next;		//step b.5
			} while (luthfi == LAST || musthafa->rollNumber > newNode->rollNumber);		// step b.3

			newNode->next = musthafa;
			luthfi->next = newNode;
		}
		case 'c': {
			newNode->next = LAST->next;			//step c.3
			LAST->next = newNode;				//step c.4
			LAST = newNode;						//step c.5
			break;
		}
		default: {
			cout << "Invalid" << endl;
			return;
		}
		}
	}

	cout << "Record added to the list" << endl;
}

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;						
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		} *
			previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { //write your answer here
	if (listEmpty()) {
		cout << "List kosong. Tidak dapat delete.\n";
		return false;
	}

	cout << "a) Delete from the beginning" << endl;
	cout << "b) Delete end of the list" << endl;
	cout << "c) Delete between two nodes in the list" << endl;
	cout << "Masukkan Pilihan (a-c): ";
	char pilihan;
	cin >> pilihan;

	switch (pilihan) {
	case 'a': {
		if (LAST->next == LAST) {					//step a.1 if LAST points to itself
			LAST = NULL;							//step a.1.c
			delete LAST;
			break;									//step a.1.b
		}
		else {
			Node* musthafa = LAST->next;				//step a.2
			LAST->next = musthafa->next;				//step a.3
			delete musthafa;							//step a.4
		}
		break;
	}
	case 'b': {
		Node* luthfi = LAST->next;					//step b.1
		Node* musthafa = LAST->next;				//step b.2

		while (luthfi != LAST) {					//step b.3
			luthfi = musthafa;						//step b.4
			musthafa = musthafa->next;				//step b.5
		}

		luthfi->next = LAST->next;
		LAST = luthfi;
		delete musthafa;
		break;
	}
	case 'c': {
		int rollno;
		cout << "Masukkan angka yang mau dihapus: ";
		cin >> rollno;

		Node* luthfi, * musthafa;

		if (search(rollno, &luthfi, &musthafa)) {
			musthafa = LAST;							//Step c.1
			luthfi = LAST->next;					//Step c.2.a

			while (luthfi != LAST) {				//Step c.2.b
				luthfi = luthfi->next;			//Step c.2.c
			}

			luthfi->next = LAST->next;			//Step c.3
			luthfi = LAST;						//Step c.4
			delete musthafa;							//Step c.5
		}
		else {
			cout << "Roll number not found in the list" << endl;
			return false;
		}
		break;

	}
	default: {
		cout << "Invalid choice" << endl;
		return false;
	}
	}

	cout << "Record deleted from the list" << endl;
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': { obj.addNode();
				break;
			}
			case '2': {obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
