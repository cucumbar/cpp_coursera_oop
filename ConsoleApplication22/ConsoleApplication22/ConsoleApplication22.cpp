#include <iostream>
#include <string>
#include <vector>

using namespace std;

class People {
public:
	People(string name, string act) : Name(name), Activity(act)
	{}
	
	virtual void Walk(string destination) {
		cout << Activity << ": " << Name << " walks to: " << destination << endl;
	}

public:
	const string Name;
	const string Activity;
};

class Student : public People {
public:

	Student(string name, string favouriteSong) : People(name, "Student"), FavouriteSong(favouriteSong) 
	{}

	void Learn() {
		cout << Activity << ": " << Name << " learns" << endl;
	}

	void Walk(string destination) {
		cout << Activity << ": " << Name << " walks to: " << destination << endl;
		cout << Activity << ": " << Name << " sings a song: " << FavouriteSong << endl;
	}

	void SingSong() {
		cout << Activity << ": " << Name << " sings a song: " << FavouriteSong << endl;
	}

public:
	const string FavouriteSong;
};


class Teacher : public People{
public:

	Teacher(const string& name, const string& subject) : People(name, "Teacher"), Subject(subject)
	{}

	void Teach() {
		cout << Activity << ": " << Name << " teaches: " << Subject << endl;
	}

public:
	const string Subject;
};


class Policeman : public People {
public:
	Policeman(string name) : People(name, "Policeman") {
	}

	void Check(People& t) const {
		cout << Activity << ": " << Name << " checks " << t.Activity << ". " << t.Activity << "'s name is: " << t.Name << endl;
	}

};


void VisitPlaces(People& t, vector<string> places) {
	for (auto p : places) {
		t.Walk(p);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}


//  Teacher: Jim walks to : Moscow
//	Teacher : Jim walks to : London
//	Policeman : Bob checks Student.Student's name is: Ann
//	Student : Ann walks to : Moscow
//	Student : Ann sings a song : We will rock you
//	Student : Ann walks to : London
//	Student : Ann sings a song : We will rock you