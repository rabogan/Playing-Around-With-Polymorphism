#include<iostream>
#include<vector>
#include<sstream>
#include<exception>
using namespace std;

class Animal {
protected:
	string name;
	double weight;
public:
	Animal() {
	}

	Animal(string name, double weight):name(name),weight(weight) {
	}

	virtual int killCalculation() const{
		throw logic_error("Not yet implemented!\n");
		return -1;
	}

	virtual void howManyChickens()const {
		int chickens = killCalculation();
		if (chickens <= 1)
			cout << "It'll take just one chicken to kill one " << getName() << "\n";
		cout << "It'll take " << ceil(chickens) << " chickens to kill one " << getName() << "\n";
	}

	virtual Animal* Clone() const {
		throw logic_error("Not implemented. Do override");
		return nullptr;
	}

	virtual ~Animal() {
	}

	virtual string getName()const {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	int getWeight()const {
		return weight;
	}

	void setWeight(double weight){
		this->weight = weight;
	}
};

class MammalianPrey:public Animal {
private:
	int number = 1;
public:
	MammalianPrey() {
	}

	MammalianPrey(string name, double weight, int number) :Animal(name, weight), number(number) {
	}

	virtual int killCalculation() const override{
		return weight * 3.456;
	}

	virtual void howManyChickens()const override{
		Animal::howManyChickens();
		if (number == 1)
			return;
		cout << "To kill " << number << " " << name << "s, that's gonna be " << killCalculation()*number << " chickens!\n";
	}

	virtual MammalianPrey* Clone() const {
		return new MammalianPrey(*this);
	}

	void setNumber(int num) {
		number = num;
	}
	int getNumber() const{
		return number;
	}
};

class MonsterPrey :public Animal {
private:
	bool asleep;
public:
	MonsterPrey() {
	}

	MonsterPrey(string name, double weight) :Animal(name, weight), asleep(false) {
	}

	virtual int killCalculation() const override {
		return weight * 12.5238;
	}

	virtual void howManyChickens()const override {
		Animal::howManyChickens();
		if(asleep)
			cout << "It takes fewer chickens to kill a sleeping " << name << ": to achieve this, we need " << killCalculation() * 0.849 << " chickens!\n";
	}

	virtual MonsterPrey* Clone() const {
		return new MonsterPrey(*this);
	}

	void setStatus(bool status) {
		asleep = status;
	}
	bool isAwake() {
		return asleep;
	}
};

class KillCountRecord {
protected:
	vector<Animal*>animals;
public:
	void AddAnimal(const Animal& any) {
		animals.push_back(any.Clone());
	}

	virtual void ShowTheBattles() const {
		cout << "*********************************\n";
		cout << "Welcome to the chicken kill count, where we calculate the number of chickens needed to kill all sorts of things!\n";
		cout << "The burning question:  how many chickens are needed to kill something?\n";
		cout << "*********************************\n";
		for (auto animalPtr : animals)
			animalPtr->howManyChickens();
	}
	virtual ~KillCountRecord() {
		for (auto animalPtr : animals) {
			delete animalPtr;
		}
		animals.clear();
	}
};

void initialize(KillCountRecord*killCounter) {
	MammalianPrey rat("rat", 4.6, 1);
	MammalianPrey tiger("tiger", 890, 5);

	MonsterPrey predator("Predator", 1802);
	predator.setStatus(true);

	killCounter->AddAnimal(rat);
	killCounter->AddAnimal(tiger);
	killCounter->AddAnimal(predator);

	MammalianPrey human;
	human.setName("Chuck Norris");
	human.setWeight(85.5);
	killCounter->AddAnimal(human);
}

int main() {
	KillCountRecord *killCounter = new KillCountRecord();
	initialize(killCounter);

	killCounter->ShowTheBattles();

	delete killCounter;
	killCounter = nullptr;

	cout << "Be good people!\n";
	return 0;
}