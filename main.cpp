#include"Header.h"
int main()
{       
	    string s;
		int c[6], m[6];
		string name[2];
		int start, end;
		TAmanagement ta(name, c, m);
		for (int z = 0; z < 2; z++)
		{
			for (int j=0 ,i = 1; j < 3 || i < 6 ; j++ , i=i+2)
			{
				 int time = 0;
				cout << "\n\n start of day " << j + 1 <<"  week  "<< z+1 << endl << endl;
				s = "\n\n start of day " + to_string(j + 1) + " week " + to_string(z + 1) +"\n\n";
				ta.write_into_file(s);
				ta.get_student();

					if (c[i] > m[i])
					{
						end = c[i];
						start = m[i - 1];
					}
					else
					{
						end = m[i];
						start = c[i - 1];
					}
					time = start;
					cout << "Start time  " << start << "   End Time   " << end << endl;
					s = "Start time "+to_string(start)+" End Time "+to_string(end)+"\n\n";
					ta.write_into_file(s);
						do
						{
							ta.student_to_laptopqueue(time);
							ta.deal_with_lapqueue(time);
							ta.deal_with_TAqueue(time);
							time++;
						} while (time != end);
				cout << "\n \n END OF THE DAY " << j + 1 << "  week  " << z + 1 << endl << endl;
				s = "\n\nEND OF THE DAY " + to_string(j + 1) + " week " + to_string(z + 1) + "\n\n";
				ta.write_into_file(s);
				ta.empty_queue();
			}
		}
		
			return 0;
}