#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int i,j,k;
	map<char,string>c2s;
	const char transStr1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
	for(i=0; transStr1[i]; ++i)
	{
		string s;
		for(j=0;j<5;++j)
		{
			if(i&(0x10>>j)) s+='1';
			else s+='0';
		}
		c2s[transStr1[i]]=s;
	}
	map<string,char>s2c;
	
	s2c["101"] = ' ';
	s2c["000000"] = '\'';
	s2c["000011"] = ',';
	s2c["10010001"] = '-';
	s2c["010001"] = '.';
	s2c["000001"] = '?';
	s2c["100101"] = 'A';
	s2c["10011010"] = 'B';
	s2c["0101"] = 'C';
	s2c["0001"] = 'D';
	s2c["110"] = 'E';
	s2c["01001"] = 'F';
	s2c["10011011"] = 'G';
	s2c["010000"] = 'H';
	s2c["0111"] = 'I';
	s2c["10011000"] = 'J';
	s2c["0110"] = 'K';
	s2c["00100"] = 'L';
	s2c["10011001"] = 'M';
	s2c["10011110"] = 'N';
	s2c["00101"] = 'O';
	s2c["111"] = 'P';
	s2c["10011111"] = 'Q';
	s2c["1000"] = 'R';
	s2c["00110"] = 'S';
	s2c["00111"] = 'T';
	s2c["10011100"] = 'U';
	s2c["10011101"] = 'V';
	s2c["000010"] = 'W';
	s2c["10010010"] = 'X';
	s2c["10010011"] = 'Y';
	s2c["10010000"] = 'Z';

	string input;
	while(getline(cin,input))
	{
		string codeStr;
		for(i=0; i<input.size(); ++i)
			codeStr += c2s[input[i]];
		for(i=0,j=0; j<codeStr.size(); ++j)
		{
			auto ite = s2c.find(codeStr.substr(i,j-i+1));
			if(ite != s2c.end())
			{
				putchar(ite->second);
				i=j+1;
			}
		}
		puts("");
	}
	return 0;
}