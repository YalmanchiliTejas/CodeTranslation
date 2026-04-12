#include<iostream>
using namespace std;

string decode(string s)
{
  string ans;
  string map[]=
    {
      "00000",
      "00001",
      "00010",
      "00011",
      "00100",
      "00101",
      "00110",
      "00111",
      "01000",      
      "01001",
      "01010",
      "01011",
      "01100",
      "01101",
      "01110",
      "01111",

      "10000",
      "10001",
      "10010",
      "10011",
      "10100",
      "10101",
      "10110",
      "10111",
      "11000",      
      "11001",
      "11010",
      "11011",
      "11100",
      "11101",
      "11110",
      "11111"     
    };
  for(int i=0;i<s.size();i++)
    {
      if(s[i]>='A'&&s[i]<='Z')
	ans+=map[s[i]-'A'];
      else if(s[i]==' ')
	ans+="11010";
      else if(s[i]=='.')
	ans+="11011";
      else if(s[i]==',')
	ans+="11100";
      else if(s[i]=='-')
	ans+="11101";
      else if(s[i]=='\'')
	ans+="11110";
      else if(s[i]=='?')
	ans+="11111";
    }

  return ans;
}

string encode(string s)
{
  string ans;
  string code[]={
    "101",
    "000000",
    "000011",
    "10010001",
    "010001",
    "000001",
    "100101",
    "10011010",
    "0101",
    "0001",
    "110",
    "01001",
    "10011011",
    "010000",
    "0111",
    "10011000",
    "0110",
    "00100",
    "10011001",
    "10011110",
    "00101",
    "111",
    "10011111",
    "1000",
    "00110",
    "00111",
    "10011100",
    "10011101",
    "000010",
    "10010010",
    "10010011",
    "10010000"
};
  string charset=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  for(int i=0;i<32;i++)
    {
      if(s.find(code[i])==0)
	{
	  ans+=charset[i];
	  s=s.substr(code[i].size());
	  i=-1;
	}
    }
  //  cout<<s<<endl;
  return ans;
}

int main()
{
  string s;

  for(;getline(cin, s);)
    cout<<encode(decode(s))<<endl;
  
}