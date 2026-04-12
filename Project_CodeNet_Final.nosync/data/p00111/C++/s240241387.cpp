#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

string code[256];

int main() {
	int i;
	for(i=0;i<256;i++)code[i]="2";
	code[' ']="101";
	code['\'']="000000";
	code[',']="000011";
	code['-']="10010001";
	code['.']="010001";
	code['?']="000001";
	code['A']="100101";
	code['B']="10011010";
	code['C']="0101";
	code['D']="0001";
	code['E']="110";
	code['F']="01001";
	code['G']="10011011";
	code['H']="010000";
	code['I']="0111";
	code['J']="10011000";
	code['K']="0110";
	code['L']="00100";
	code['M']="10011001";
	code['N']="10011110";
	code['O']="00101";
	code['P']="111";
	code['Q']="10011111";
	code['R']="1000";
	code['S']="00110";
	code['T']="00111";
	code['U']="10011100";
	code['V']="10011101";
	code['W']="000010";
	code['X']="10010010";
	code['Y']="10010011";
	code['Z']="10010000";
	string str,buf;
	while(getline(cin,str)){
		buf="";
		for(i=0;i<str.size();i++){
			if(isalpha(str[i])){
				buf+=(str[i]-'a'&16)?"1":"0";
				buf+=(str[i]-'a'&8)?"1":"0";
				buf+=(str[i]-'a'&4)?"1":"0";
				buf+=(str[i]-'a'&2)?"1":"0";
				buf+=(str[i]-'a'&1)?"1":"0";
			}else if(str[i]==' '){
				buf+="11010";
			}else if(str[i]=='.'){
				buf+="11011";
			}else if(str[i]==','){
				buf+="11100";
			}else if(str[i]=='-'){
				buf+="11101";
			}else if(str[i]=='\''){
				buf+="11110";
			}else if(str[i]=='?'){
				buf+="11111";
			}
		}
//cout<<buf<<endl;
		int j,k;
		for(i=0;i<buf.size();){
			for(j=1;i+j<=buf.size();j++){
				for(k=32;k<128;k++){
					if(buf.substr(i,j)==code[k]){
						cout<<(char)k;
						goto aaa;
					}
				}
			}
			break;
			aaa:;
			i+=j;
		}
		cout<<endl;
	}
	return 0;
}