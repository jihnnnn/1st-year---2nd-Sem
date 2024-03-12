#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int LINE = 35;
struct Player {
	string nickname;
	int age;
	double scores[5];
};

struct Node {
	Player player;
	Node* next;
};

Node* head = nullptr;

void addRecord(const Player& player);
void viewRecords();
void computeAverage();
void showMaxAverage();
void showMinAverage();
void openFile();
void closeFile();
void Menu();
void END();

int main(){
	Player p;
	char choice = 0;
	int playerNum = 0;
	do{	
		
		Menu();
		cout << "Enter Choice: "; 
		cin >> choice;
		
		switch(choice){
			case '1':
				system("cls");
				cout << "===Add Player Record===\n";
				cout << string(25, '-') << endl;

				if(playerNum < 5){
				cout << "Enter Player Name: ";
					cin >> p.nickname;
					cout << "Enter Player Age: ";
					cin >> p.age;
					
					for(int i = 0; i < 5; i++){
						cout << "Enter Score " << i+1 << ": ";
						cin >> p.scores[i];
					}
					
				addRecord(p);
				playerNum++;
				END();
				
				}
				else{
					cout << "Record List Full!\n";
					END();
				}
				break;
			case '2':
				system("cls");
				cout << "===View Player Record===\n";
				cout << string(25, '-') << endl;
				if(playerNum >= 1){
					viewRecords();
					END();	
				}
				else{
					cout << "Please Add Record First!\n\n";
					END();
				}
				break;
			case '3':
				system("cls");
				cout << "===Compute Player Average===\n";
				cout << string(25, '-') << endl;
				if(playerNum >= 1){
					computeAverage();
					END();
				}
				else{
					cout << "Please Add Record First!\n\n";
					END();
				}
				break;
			case '4':
				system("cls");
				cout << "===Show Max Average===\n";
				cout << string(25, '-') << endl;
				if(playerNum >= 1){
					showMaxAverage();
					END();
				}
				else{
					cout << "Please Add Record First!\n\n";
					END();
				}
				break;
			case '5':
				system("cls");
				cout << "===Show Min Average===\n";
				cout << string(25, '-') << endl;
				if(playerNum >= 1){
					showMinAverage();
					END();
				}
				else{
					cout << "Please Add Record First!\n\n";
					END();
				}
				break;
			case '6':
				system("cls");
				cout << "===Open File===\n";
				cout << string(25, '-') << endl;
				if(playerNum >= 1){
					openFile();
					END();
				}
				else{
					cout << "Please Add Record First!\n\n";
					END();
				}
				break;
			case '7':
				system("cls");
				cout << "===Close File===\n";
				cout << string(25, '-') << endl;
				if(playerNum >= 1){
					closeFile();
					END();
				}
				else{
					cout << "Please Add Record First!\n\n";
					END();
				}
				break;
			case '8':
				system("cls");
				cout << "Program Ended. Thank You!\n";
				
				return 0;
				break;
			default:
				system("cls");
				cout << "Invalid Option!";
				END();
				break;
		}
	}
	while(choice != '8');
	
	return 0;
}

void END(){
	system("pause");
	system("cls");
}
void Menu(){
	cout << string(LINE, '=') << endl;
	cout << "\t\tMENU\n";
	cout << string(LINE, '=') << endl << endl;
	cout << "1. Add Record\n";
	cout << "2. View players record\n";
	cout << "3. Compute for the average\n";
	cout << "4. Show the player(s) who get the max average\n";
	cout << "5. Show the player(s) who get the min average\n";
	cout << "6. Open the file\n";
	cout << "7. Close the File\n";
	cout << "8. Exit\n";
}
void addRecord(const Player& player) {
	Node* newNode = new Node;
	newNode->player = player;
	newNode->next = head;
	head = newNode;
}

void viewRecords() {
	Node* current = head;
	while (current != nullptr) {
		cout << "Nickname: " << current->player.nickname << endl; cout << "Age: " << current->player.age << endl;
		cout << "Scores: ";
		for (int i = 0; i < 5; ++i) {
			cout << current->player.scores[i] << " ";
			}
		cout << endl;
		cout << "----------------------------------" << endl;
		current = current->next;
		}
}

void computeAverage() { 
	Node* current = head;
	while (current != nullptr) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i];
		}
		
		double average = sum / 5.0;
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Average Score: " << average << endl;
		cout << "----------------------------------" << endl;
		current = current->next;
	}
}

void showMaxAverage() { 
	Node* current = head;
	double maxAverage = -1; // Initialize to a non-valid value
	while (current != NULL) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i];
		}
		
		double average = sum / 5.0;
		if (average > maxAverage) {
			maxAverage = average;
		}
		current = current->next;
	}
	// Now, iterate again to display players with the max average
	current = head;
	while (current != NULL) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i]; 
		}
		double average = sum / 5.0;
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
	double minAverage = 100; // Initialize to a value higher than the possible average 
	while (current != NULL) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i]; 
	}
		double average = sum / 5.0;
		if (average < minAverage) {
			minAverage = average;
		}
		current = current->next;
	}
	// Now, iterate again to display players with the min average
	current = head;
	while (current != nullptr) { 
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i]; 
		}
	double average = sum / 5.0; 
	if (average == minAverage) {
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Average Score: " << average << endl;
		cout << "----------------------------------" << endl; }
	current = current->next; }
}

void openFile() {
	ofstream outFile("player_records.txt"); 
	Node* current = head;
	while (current != nullptr) {
		outFile << current->player.nickname << endl; 
		outFile << current->player.age << endl;
		
		for (int i = 0; i < 5; ++i) {
			outFile << current->player.scores[i] << " "; 
		}
		outFile << endl;
		current = current->next; 
	}
	outFile.close();
	cout << "Records saved to 'player_records.txt'." << endl; 
}

void closeFile() {
	cout << "File closed." << endl;
}