#include <iostream>
#include <string>
using namespace std;

struct Player {
	string nickname;
	int age;
	double score1;
	double score2;
};

struct Node {
	Player player;
	Node* next;
};

Node* head = NULL;

void addRecord(const Player& player) {
	Node* newNode = new Node;
	newNode->player = player;
	newNode->next = head;
	head = newNode;
}

void viewRecords() {
	Node* current = head;
	while (current != NULL) {
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Age: " << current->player.age << endl;
		cout << "Score 1: " << current->player.score1 << endl;
		cout << "Score 2: " << current->player.score2 << endl;
		cout << "----------------------------------" << endl;
		current = current->next;
	}
}

void computeAverage() {
	Node* current = head; while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Average Score: " << average << endl;
		cout << "----------------------------------" << endl; current = current->next;
	}
}

void showMaxAverage() {
	Node* current = head;
	double maxAverage = -1; // Initialize to a non-valid value
	while (current != NULL){
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average > maxAverage) {
			maxAverage = average;
		}
		current = current->next;
	}
	// Now, iterate again to display players with the max average
	current = head;
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average == maxAverage) {
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl;
		}
	current = current->next;
	}
}

void showMinAverage() {
	Node* current = head;
	double minAverage = 999999; // Initialize to a large value
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average < minAverage) {
			minAverage = average;
			}
		current = current->next;
	}
	// Now, iterate again to display players with the min average
	current = head;
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
			if (average == minAverage) {
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl;
			}
	current = current->next;
	}
}

void menu(){
	cout << "------------------\n";
	cout << "\tMENU\n";
	cout << "------------------\n";
	cout << "1. Add Player Record\n";
	cout << "2. View Records\n";
	cout << "3. Compute Average\n";
	cout << "4. Show Max Average\n";
	cout << "5. Show Min Average\n";
	cout << "6. Exit\n\n";
}
int main(){
	Player p;
	char choice;
	int playerCount = 0;
	do{
	
		choice = '0';
		menu();
		cout << "Enter Choice: ";
		cin >> choice;
		system("cls");
		
		switch(choice){
			case '1':
				if(playerCount < 5){
					cout << "=== Add Player Record ===\n";
					cout << "Enter Player Name: ";
					cin >> p.nickname;
					cout << "Enter Player Age: ";
					cin >> p.age;
					cout << "Enter Score 1: ";
					cin >> p.score1;
					cout << "Enter Score 2: ";
					cin >> p.score2;
					addRecord(p);
					
					cout << "\nPlayer Record Added Successfully!\n\n";
					
					playerCount++;
					system("pause");
					system("cls");
				}
				else{
					cout << "Record List Full!";
					system("pause");
					system("cls");
				}
				
				break;
			case '2':
				cout << "=== View Records ===\n";
				viewRecords();
				system("pause");
				system("cls");
				break;
			case '3':
				cout << "=== Compute the Average Scores ===\n";
				computeAverage();
				system("pause");
				system("cls");
				break;
			case '4':
				cout << "=== Show Max Average ===\n";
				showMaxAverage();
				system("pause");
				system("cls");
				break;
			case '5':
				cout << "=== Show Min Average ===\n";
				showMinAverage();
				system("pause");
				system("cls");
				break;
			case '6':
				cout << "Program Exited.\n";
				return 0;
				break;
			default: 
				cout << "Invalid Input!";
				system("pause");
				system("cls");
		}
	}
	while(choice != '6');
	return 0;
}