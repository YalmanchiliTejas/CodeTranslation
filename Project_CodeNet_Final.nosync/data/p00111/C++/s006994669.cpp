#include <iostream>
#include <string>
#include <map>
using namespace std;

char pa[] = " .,-'?";

int main()
{
	map<string,char> m;
	m["101"     ] = ' ';
	m["000000"  ] = '\'';
	m["000011"  ] = ',';
	m["10010001"] = '-';
	m["010001"  ] = '.';
	m["000001"  ] = '?';
	m["100101"  ] = 'A';
	m["10011010"] = 'B';
	m["0101"    ] = 'C';
	m["0001"    ] = 'D';
	m["110"     ] = 'E';
	m["01001"   ] = 'F';
	m["10011011"] = 'G';
	m["010000"  ] = 'H';
	m["0111"    ] = 'I';
	m["10011000"] = 'J';
	m["0110"    ] = 'K';
	m["00100"   ] = 'L';
	m["10011001"] = 'M';
	m["10011110"] = 'N';
	m["00101"   ] = 'O';
	m["111"     ] = 'P';
	m["10011111"] = 'Q';
	m["1000"    ] = 'R';
	m["00110"   ] = 'S';
	m["00111"   ] = 'T';
	m["10011100"] = 'U';
	m["10011101"] = 'V';
	m["000010"  ] = 'W';
	m["10010010"] = 'X';
	m["10010011"] = 'Y';
	m["10010000"] = 'Z';

	string str,key;
	while(getline(cin,str))
	{
		string xxx;
		for(int i=0; i<str.size(); i++)
		{
			if('A'<=str[i] && str[i]<='Z')
			{
				int x=str[i]-'A';
				for(int j=0; j<5; j++)
				{
					xxx += ((x>>(4-j))&1) + '0';
				}
			}
			else
			{
				switch(str[i])
				{
					case ' ' : xxx+="11010"; break;
					case '.' : xxx+="11011"; break;
					case ',' : xxx+="11100"; break;
					case '-' : xxx+="11101"; break;
					case '\'': xxx+="11110"; break;
					case '?' : xxx+="11111"; break;
				}
			}
		}

		key="";
		for(int i=0; i<xxx.size(); i++)
		{
			key+=xxx[i];
			if(m.find(key)!=m.end())
			{
				cout << m[key];
				key="";
			}
		}
		cout << endl;
	}
}