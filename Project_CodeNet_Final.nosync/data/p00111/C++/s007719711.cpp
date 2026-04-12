#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF=1e9;
const int MOD=100000;
string rec1(string in){
	string res="";
	map<char,string> s;
	s['A']="00000";
	s['B']="00001";
	s['C']="00010";
	s['D']="00011";
	s['E']="00100";
	s['F']="00101";
	s['G']="00110";
	s['H']="00111";
	s['I']="01000";
	s['J']="01001";
	s['K']="01010";
	s['L']="01011";
	s['M']="01100";
	s['N']="01101";
	s['O']="01110";
	s['P']="01111";
	s['Q']="10000";
	s['R']="10001";
	s['S']="10010";
	s['T']="10011";
	s['U']="10100";
	s['V']="10101";
	s['W']="10110";
	s['X']="10111";
	s['Y']="11000";
	s['Z']="11001";
	s[' ']="11010";
	s['.']="11011";
	s[',']="11100";
	s['-']="11101";
	s['\'']="11110";
	s['?']="11111";
	REP(i,in.size())res+=s[in[i]];
	return res;
}
string rec2(string in){
	string res="",t="";
	map<string,char>s;
	s["101"]=' ';
	s["000000"]='\'';
	s["000011"]=',';
	s["10010001"]='-';
	s["010001"]='.';
	s["000001"]='?';
	s["100101"]='A';
	s["10011010"]='B';
	s["0101"]='C';
	s["0001"]='D';
	s["110"]='E';
	s["01001"]='F';
	s["10011011"]='G';
	s["010000"]='H';
	s["0111"]='I';
	s["10011000"]='J';
	s["0110"]='K';
	s["00100"]='L';
	s["10011001"]='M';
	s["10011110"]='N';
	s["00101"]='O';
	s["111"]='P';
	s["10011111"]='Q';
	s["1000"]='R';
	s["00110"]='S';
	s["00111"]='T';
	s["10011100"]='U';
	s["10011101"]='V';
	s["000010"]='W';
	s["10010010"]='X';
	s["10010011"]='Y';
	s["10010000"]='Z';
	REP(i,in.size()){
		t+=in[i];
		if(s.find(t)!=s.end()){
			res+=s[t];
			t="";
		}
	}
	return res;
}
int main(){
	string in;
	while(getline(cin,in)){
		in=rec1(in);
		cout<<rec2(in)<<endl;
	}
}