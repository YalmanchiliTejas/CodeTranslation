#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  map<char,string>in;
  in['A']="00000";
  in['B']="00001";
  in['C']="00010";
  in['D']="00011";
  in['E']="00100";
  in['F']="00101";
  in['G']="00110";
  in['H']="00111";
  in['I']="01000";
  in['J']="01001";
  in['K']="01010";
  in['L']="01011";
  in['M']="01100";
  in['N']="01101";
  in['O']="01110";
  in['P']="01111";
  in['Q']="10000";
  in['R']="10001";
  in['S']="10010";
  in['T']="10011";
  in['U']="10100";
  in['V']="10101";
  in['W']="10110";
  in['X']="10111";
  in['Y']="11000";
  in['Z']="11001";
  in[' ']="11010";
  in['.']="11011";
  in[',']="11100";
  in['-']="11101";
  in['\'']="11110";
  in['?']="11111";
  map<string,char>out;
  out["101"]=' ';
  out["000000"]='\'';
  out["000011"]=',';
  out["10010001"]='-';
  out["010001"]='.';
  out["000001"]='?';
  out["100101"]='A';
  out["10011010"]='B';
  out["0101"]='C';
  out["0001"]='D';
  out["110"]='E';
  out["01001"]='F';
  out["10011011"]='G';
  out["010000"]='H';
  out["0111"]='I';
  out["10011000"]='J';
  out["0110"]='K';
  out["00100"]='L';
  out["10011001"]='M';
  out["10011110"]='N';
  out["00101"]='O';
  out["111"]='P';
  out["10011111"]='Q';
  out["1000"]='R';
  out["00110"]='S';
  out["00111"]='T';
  out["10011100"]='U';
  out["10011101"]='V';
  out["000010"]='W';
  out["10010010"]='X';
  out["10010011"]='Y';
  out["10010000"]='Z';

  string s;
  while(getline(cin,s)){
    string a="";
    rep(i,s.size())a+=in[s[i]];
    int to=0;
    string tmp="";
    while(to<a.size()){
      tmp+=a[to];
      to++;
      if(out[tmp]){
	cout<<out[tmp];
	tmp="";
      }
    }
    cout<<endl;
  }
}