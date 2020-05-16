#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
#include<conio.h>
#include<string>
using namespace std;
typedef struct StudentStructure
{
	string firstName;
	string lastName;
	int enterTime;
	int numQuestions;
	int numAnswered;
	string laptopSerialNum;
	string day;
}student;
typedef struct TAStructure
{
	string name; // only use first names for the TAs
	int startTimes[3];
	int endTimes[3];
	student studentWithTA;
	int minute;
}TA;

class TAmanagement
{
private:
	queue<student*> TAqueue_Students;
	queue<student*> student_queue;
	queue<TA*>TAqueue;
	queue<student*> laptopque;
	stack<string> laptop;
	ifstream myfile;
	ofstream outfile;
public:
	TAmanagement(string name[],int c[],int m[]);
	~ TAmanagement();
	void student_to_laptopqueue(int time);
	void deal_with_lapqueue(int time);
	void deal_with_TAqueue(int time);
	void get_student();
	void empty_queue();
	void write_into_file(string s);
	
};