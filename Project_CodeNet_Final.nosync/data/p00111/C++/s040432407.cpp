#include <iostream>
#include <string>
#include <vector>
#include <map>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	map<char,string> ID;
	ID['A'] = "00000";
	ID['B'] = "00001";
    ID['C'] = "00010";
    ID['D'] = "00011";
    ID['E'] = "00100";
    ID['F'] = "00101";
    ID['G'] = "00110";
    ID['H'] = "00111";
    ID['I'] = "01000";
    ID['J'] = "01001";
    ID['K'] = "01010";
    ID['L'] = "01011";
    ID['M'] = "01100";
    ID['N'] = "01101";
    ID['O'] = "01110";
    ID['P'] = "01111";
    ID['Q'] = "10000";
    ID['R'] = "10001";
    ID['S'] = "10010";
    ID['T'] = "10011";
    ID['U'] = "10100";
    ID['V'] = "10101";
    ID['W'] = "10110";
    ID['X'] = "10111";
    ID['Y'] = "11000";
    ID['Z'] = "11001";
    ID[' '] = "11010";
    ID['.'] = "11011";
    ID[','] = "11100";
    ID['-'] = "11101";
    ID['\''] = "11110";
    ID['?'] = "11111";

	map<string,char> Id;
	Id["101"] = ' ';
	Id["000000"] = '\'';
	Id["000011"] = ',';
	Id["10010001"] = '-';
	Id["010001"] = '.';
	Id["000001"] = '?';
	Id["100101"] = 'A';
	Id["10011010"] = 'B';

	Id["0101"] = 'C';
	Id["0001"] = 'D';
	Id["110"] = 'E';
	Id["01001"] = 'F';
	Id["10011011"] = 'G';
	Id["010000"] = 'H';
	Id["0111"] = 'I';
	Id["10011000"] = 'J';

	Id["0110"] = 'K';
	Id["00100"] = 'L';
	Id["10011001"] = 'M';
	Id["10011110"] = 'N';
	Id["00101"] = 'O';
	Id["111"] = 'P';
	Id["10011111"] = 'Q';
	Id["1000"] = 'R';
	
	Id["00110"] = 'S';
	Id["00111"] = 'T';
	Id["10011100"] = 'U';
	Id["10011101"] = 'V';
	Id["000010"] = 'W';
	Id["10010010"] = 'X';
	Id["10010011"] = 'Y';
	Id["10010000"] = 'Z';
	
	string s;
	while(getline(cin,s))
	{
		if(cin.eof()) break;

		string temp;
		rep(i,s.size())
		{
			temp += ID[s[i]];
		}

		string id = "";
		vector<char> ans;
		rep(i,temp.size())
		{
			id += temp[i];
			if(Id.count(id) != 0)
			{
				ans.push_back(Id[id]);
				id = "";
			}
		}

		rep(i,ans.size())
		{
			cout << ans[i];
		}

		cout << endl;
	}
	return 0;
}