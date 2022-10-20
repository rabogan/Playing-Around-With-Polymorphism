#include<iostream>
#include<vector>
using namespace std;

class ClubEmployee {
protected:
	string name;
	int baseSalary = 100.0;
public:
	ClubEmployee() {
		cout << "Club Employee\n";
	}
	void setName(string forename) {
		name = forename;
	}
	void printSalary() {
		cout << name << " receives a salary of " << baseSalary << "\n";
	}
	~ClubEmployee() {
		cout << "~Club Employee\n";
	}
};

class Player : public ClubEmployee {
protected:
	int playerSalary = 1000000;
public:
	Player() {
		cout << "Player\n";
	}
	void printSalary() {
		cout << name << " receives a salary of " << playerSalary << "\n";
	}
	~Player() { cout << "~Player\n"; }
};

int main() {
	ClubEmployee bill;
	Player salah;
	bill.setName("Bill");
	salah.setName("Salah");

	bill.printSalary();
	salah.printSalary();

	ClubEmployee* employeePointer = &bill;
	Player* playerPointer = &salah;
	ClubEmployee* playerPointer2 = &salah;  
	ClubEmployee* playerPointer3 = new Player;
	playerPointer3->setName("DarwinNunez");

	employeePointer->printSalary();
	playerPointer->printSalary();
	playerPointer2->printSalary();   //Mo Salah might be VERY unhappy with the new salary
	playerPointer3->printSalary();
	delete playerPointer3;
	return 0;
}