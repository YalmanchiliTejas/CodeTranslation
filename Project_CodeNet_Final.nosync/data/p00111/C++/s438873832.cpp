#include<iostream>
#include<string>
using namespace std;

string code(char c)
{
	if(c=='A') return "00000";
	if(c=='B') return "00001";
	if(c=='C') return "00010";
	if(c=='D') return "00011";
	if(c=='E') return "00100";
	if(c=='F') return "00101";
	if(c=='G') return "00110";
	if(c=='H') return "00111";
	if(c=='I') return "01000";
	if(c=='J') return "01001";
	if(c=='K') return "01010";
	if(c=='L') return "01011";
	if(c=='M') return "01100";
	if(c=='N') return "01101";
	if(c=='O') return "01110";
	if(c=='P') return "01111";
	if(c=='Q') return "10000";
	if(c=='R') return "10001";
	if(c=='S') return "10010";
	if(c=='T') return "10011";
	if(c=='U') return "10100";
	if(c=='V') return "10101";
	if(c=='W') return "10110";
	if(c=='X') return "10111";
	if(c=='Y') return "11000";
	if(c=='Z') return "11001";
	if(c==' ') return "11010";
	if(c=='.') return "11011";
	if(c==',') return "11100";
	if(c=='-') return "11101";
	if(c=='\'') return "11110";
	if(c=='?') return "11111";
}

char encode(string c)
{
	if(c=="101") return ' ';
	if(c=="000000") return '\'';
	if(c=="000011") return ',';
	if(c=="10010001") return '-';
	if(c=="010001") return '.';
	if(c=="000001") return '?';
	if(c=="100101") return 'A';
	if(c=="10011010") return 'B';
	if(c=="0101") return 'C';
	if(c=="0001") return 'D';
	if(c=="110") return 'E';
	if(c=="01001") return 'F';
	if(c=="10011011") return 'G';
	if(c=="010000") return 'H';
	if(c=="0111") return 'I';
	if(c=="10011000") return 'J';
	if(c=="0110") return 'K';
	if(c=="00100") return 'L';
	if(c=="10011001") return 'M';
	if(c=="10011110") return 'N';
	if(c=="00101") return 'O';
	if(c=="111") return 'P';
	if(c=="10011111") return 'Q';
	if(c=="1000") return 'R';
	if(c=="00110") return 'S';
	if(c=="00111") return 'T';
	if(c=="10011100") return 'U';
	if(c=="10011101") return 'V';
	if(c=="000010") return 'W';
	if(c=="10010010") return 'X';
	if(c=="10010011") return 'Y';
	if(c=="10010000") return 'Z';

	return '*';
}

int main()
{
	string in;
	while(getline(cin,in)) 
	{
		string co="";
		for(int i = 0; i < in.size(); ++i)
		{
			co+=code(in[i]);
		}
		string tmp="",ans="";
		for(int i = 0; i < co.size(); ++i)
		{
			tmp+=co[i];
			if(encode(tmp)!='*')
			{
				ans+=encode(tmp);
				tmp="";
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}