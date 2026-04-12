//Doctor's Memorable Codes
#include<bits/stdc++.h>
using namespace std;

string into(string s){
  string ret="";
  for(int i=0; i<s.length(); i++){
    if(s[i]=='A')ret+="00000";
    if(s[i]=='B')ret+="00001";
    if(s[i]=='C')ret+="00010";
    if(s[i]=='D')ret+="00011";
    if(s[i]=='E')ret+="00100";
    if(s[i]=='F')ret+="00101";
    if(s[i]=='G')ret+="00110";
    if(s[i]=='H')ret+="00111";
    if(s[i]=='I')ret+="01000";
    if(s[i]=='J')ret+="01001";
    if(s[i]=='K')ret+="01010";
    if(s[i]=='L')ret+="01011";
    if(s[i]=='M')ret+="01100";
    if(s[i]=='N')ret+="01101";
    if(s[i]=='O')ret+="01110";
    if(s[i]=='P')ret+="01111";
    if(s[i]=='Q')ret+="10000";
    if(s[i]=='R')ret+="10001";
    if(s[i]=='S')ret+="10010";
    if(s[i]=='T')ret+="10011";
    if(s[i]=='U')ret+="10100";
    if(s[i]=='V')ret+="10101";
    if(s[i]=='W')ret+="10110";
    if(s[i]=='X')ret+="10111";
    if(s[i]=='Y')ret+="11000";
    if(s[i]=='Z')ret+="11001";
    if(s[i]==' ')ret+="11010";
    if(s[i]=='.')ret+="11011";
    if(s[i]==',')ret+="11100";
    if(s[i]=='-')ret+="11101";
    if(s[i]=='\'')ret+="11110";
    if(s[i]=='?')ret+="11111";
  }
  return ret;
}

string solve(string t){
  string s=into(t);
  string ret="";
  int l=0, r=0;
  for( ; r!=s.length(); r++){
    string tmp=s.substr(l, r-l+1);//文字列の切り出し
    if(tmp=="101"){ret+=" "; l=r+1;}
    if(tmp=="000000"){ret+="\'"; l=r+1;}
    if(tmp=="000011"){ret+=","; l=r+1;}
    if(tmp=="10010001"){ret+="-"; l=r+1;}
    if(tmp=="010001"){ret+="."; l=r+1;}
    if(tmp=="000001"){ret+="?"; l=r+1;}
    if(tmp=="100101"){ret+="A"; l=r+1;}
    if(tmp=="10011010"){ret+="B"; l=r+1;}
    if(tmp=="0101"){ret+="C"; l=r+1;}
    if(tmp=="0001"){ret+="D"; l=r+1;}
    if(tmp=="110"){ret+="E"; l=r+1;}
    if(tmp=="01001"){ret+="F"; l=r+1;}
    if(tmp=="10011011"){ret+="G"; l=r+1;}
    if(tmp=="010000"){ret+="H"; l=r+1;}
    if(tmp=="0111"){ret+="I"; l=r+1;}
    if(tmp=="10011000"){ret+="J"; l=r+1;}
    if(tmp=="0110"){ret+="K"; l=r+1;}
    if(tmp=="00100"){ret+="L"; l=r+1;}
    if(tmp=="10011001"){ret+="M"; l=r+1;}
    if(tmp=="10011110"){ret+="N"; l=r+1;}
    if(tmp=="00101"){ret+="O"; l=r+1;}
    if(tmp=="111"){ret+="P"; l=r+1;}
    if(tmp=="10011111"){ret+="Q"; l=r+1;}
    if(tmp=="1000"){ret+="R"; l=r+1;}
    if(tmp=="00110"){ret+="S"; l=r+1;}
    if(tmp=="00111"){ret+="T"; l=r+1;}
    if(tmp=="10011100"){ret+="U"; l=r+1;}
    if(tmp=="10011101"){ret+="V"; l=r+1;}
    if(tmp=="000010"){ret+="W"; l=r+1;}
    if(tmp=="10010010"){ret+="X"; l=r+1;}
    if(tmp=="10010011"){ret+="Y"; l=r+1;}
    if(tmp=="10010000"){ret+="Z"; l=r+1;}
  }
  return ret;
}

int main(){
  string s;
  while(getline(cin, s))cout<<solve(s)<<endl;
  return 0;
}