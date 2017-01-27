// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main()
{



	ifstream countfile;
	countfile.open("lthree.txt");
	string line;
	string line2;
	ofstream writefile;
	writefile.open("writing.txt");

	if (countfile.is_open() && writefile.is_open())
	{
			while (getline(countfile, line))
			{
				int x = 0;
				vector<string> vec;
				stringstream ss;
				ss.str(line);
				while (getline(ss, line2, ';')) {
					vec.push_back(line2);
				}
				cout << vec[0] << ";" << vec[1] << ";" << vec[2]<<  "\n";

				ifstream myfile;
				myfile.open("categories.txt");
				string line3;
				string line4;
				while (getline(myfile, line3))
				{
					bool b1 = false;
					bool b2 = false;
					bool b3 = false;
					//bool b4 = false;

					stringstream ss;
					ss.str(line3);
					while (getline(ss, line4, ';')) {
						if (line4 == vec[0]) { b1 = true; }
						else if (line4 == vec[1]) { b2 = true; }
						else if (line4 == vec[2]) { b3 = true; }
						//else if (line4 == vec[3]) { b4 = true; }

					}
					if (b1 && b2 && b3 ) { x++; }
				}

				//if (x > 771) {
					writefile << x << ":" << vec[0] << ";" << vec[1] << ";" << vec[2]<< "\n";
				//}

				myfile.close();
			}




			countfile.close();
			writefile.close();
		}


	
	else { cout << "Unable to open file"; }




	return 0;
}

