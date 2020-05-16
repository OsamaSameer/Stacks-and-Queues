#include"header.h"

TAmanagement::TAmanagement(string name[],int c1[],int m1[])
{
	myfile.open("input.txt");
	outfile.open("output.txt");
	string num,sereal,data,sTime,eTime;
	int n;
	getline(myfile, num);
	n = stoi(num);
	for (int i = 0; i < n; i++)
	{
		getline(myfile, sereal);
		laptop.push(sereal);
	}
	getline(myfile, num);
	n = stoi(num);
	
	myfile >> name[0];
		for(int j=0;j<6;j++)// every day start time and end time
		{
			myfile >> sTime;
			int n1 = stoi(sTime);
			c1[j] = n1;
			cout << "chales" << "  " << c1[j] << endl;
		}
		myfile >> name[1];
		for (int j = 0; j < 6; j++)// every day start time and end time
		{
			myfile >> sTime;
			int n1 = stoi(sTime);
			m1[j] = n1;
			cout << "max" << "  " << m1[j] << endl;
		}

	
}
TAmanagement::~TAmanagement()
{
	myfile.close();
	outfile.close();
	cout << "bye bye";
}
void TAmanagement::student_to_laptopqueue( int time)
{
	if (!student_queue.empty())
	{
		student* temp = new student;
		temp = student_queue.front();
		if (temp->enterTime == time)
		{
			laptopque.push(temp);
			student_queue.pop();
		}
	}
}
void TAmanagement::deal_with_lapqueue(int time)
{
	string s;
	if (!laptopque.empty())
	{
		student* temp = new student;
		temp = laptopque.front();

		if (temp->numQuestions == 0 && temp->laptopSerialNum != "0")
		{
			laptop.push(temp->laptopSerialNum);
			laptopque.pop();
			cout << temp->firstName <<" has returned laptop " << temp->laptopSerialNum<<endl;
			s = temp->firstName+" has returned laptop "+temp->laptopSerialNum+"\n";
			write_into_file(s);
		}
		if (temp->enterTime + 1 == time)
		{
			temp->laptopSerialNum = laptop.top();
			cout << temp->firstName << "  " << temp->lastName << "  " << temp->laptopSerialNum <<"  "<<temp->enterTime<<endl;
			s = temp->firstName+" "+temp->lastName+" "+temp->laptopSerialNum+" "+to_string(temp->enterTime)+"\n";
			write_into_file(s);
			laptop.pop();
			laptopque.pop();
			temp->enterTime++;
			TAqueue_Students.push(temp);
		}
	}
}
void TAmanagement::deal_with_TAqueue(int time)
{
	string s;
		if (!TAqueue_Students.empty())
		{
			student* temp = new student;
			temp = TAqueue_Students.front();
			if (temp->enterTime + 5 == time)
			{
				temp->numQuestions--;
				if (temp->numQuestions != 0)
				{
					TAqueue_Students.pop();
					cout << "TA is serving to " << "   " << temp->firstName << "  " << temp->lastName << "  " << temp->numQuestions << "  " << temp->laptopSerialNum << "   " << time << endl;
					s = "TA is serving to "+temp->firstName+" "+temp->lastName+" "+to_string(temp->numQuestions)+" "+temp->laptopSerialNum+" "+to_string(time)+"\n";
					write_into_file(s);
					temp->enterTime = time;
					TAqueue_Students.push(temp);
				}
				else if (temp->numQuestions == 0)
				{
					TAqueue_Students.pop();
					cout << "Completed from TA line  " << "   " << temp->firstName << "  " << temp->lastName << "  " << temp->numQuestions << "  " << temp->laptopSerialNum << "   " << time << endl;
					s= "Completed from TA line "+temp->firstName+" "+temp->lastName+" "+to_string(temp->numQuestions)+" "+temp->laptopSerialNum+" "+to_string(time)+"\n";
					write_into_file(s);
					laptopque.push(temp);
				}

				if (!TAqueue_Students.empty())
				{
					temp = TAqueue_Students.front();
					temp->enterTime = time;
				}
			}
		}
}
void TAmanagement::empty_queue()
{
	student* st;
	while (!student_queue.empty())
	{
		st = student_queue.front();
		laptop.push(st->laptopSerialNum);
		student_queue.pop();
	}
	while (!TAqueue_Students.empty())
	{
		TAqueue_Students.pop();
	}
	while (!laptopque.empty())
	{
		laptopque.pop();
	}
}
void TAmanagement::get_student()
{
	
	string first_name,last_name,enter_time, numQuestions, numAnswered,number_student,day;

		int n;
		myfile >> number_student;
		n = stoi(number_student);
		myfile >> day;
		for (int i = 0; i < n; i++)
		{
			student* st = new student;
			myfile >> enter_time;
			st->enterTime = stoi(enter_time);
			//getting time of the student from file
			myfile >> first_name;
			st->firstName = first_name;
			//getting first name from file
			myfile >> last_name;
			st->lastName = last_name;
			//getting last name from file
			myfile >> numQuestions;
			st->numQuestions = stoi(numQuestions);
			//getting number of Questions from file
			st->day = day;
			student_queue.push(st);
		}
}
void TAmanagement::write_into_file(string s)
{
	outfile << s;
}
