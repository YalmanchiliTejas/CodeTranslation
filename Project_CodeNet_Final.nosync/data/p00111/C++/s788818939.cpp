#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




const int INF = 1000000;
const int mod = 1e9 + 7;


string calc(int n){
	string ret = "";
	for(int i=0; i<5; i++){
		ret += (char)('0' + n % 2);
		n /= 2;
	}
	reverse(all(ret));
	return ret;
}

int main(){
	map<char,string> m;
	rep(i,26) m[(char)('A' + i)] =calc(i);
	m[' '] = calc(26);
	m['.'] = calc(27);
	m[','] = calc(28);
	m['-'] = calc(29);
	m['\''] = calc(30);
	m['?'] = calc(31);
	map<string,char> mm;
	mm["101"] = ' ';
	mm["000000"] = '\'';
	mm["000011"] = ',';
	mm["10010001"] = '-';
	mm["010001"] = '.';
	mm["000001"] = '?';
	mm["100101"] = 'A';
	mm["10011010"] = 'B';
	mm["0101"] = 'C';
	mm["0001"] = 'D';
	mm["110"] = 'E';
	mm["01001"] ='F';
	mm["10011011"] = 'G';
	mm["010000"] = 'H';
	mm["0111"] = 'I';
	mm["10011000"] = 'J';
	mm["0110"] = 'K';
	mm["00100"] = 'L';
	mm["10011001"] = 'M';
	mm["10011110"] = 'N';
	mm["00101"] = 'O';
	mm["111"] = 'P';
	mm["10011111"] = 'Q';
	mm["1000"] = 'R';
	mm["00110"] = 'S';
	mm["00111"] = 'T';
	mm["10011100"] = 'U';
	mm["10011101"] = 'V';
	mm["000010"] = 'W';
	mm["10010010"] = 'X';
	mm["10010011"] = 'Y';
	mm["10010000"] = 'Z';
	string s;
	while(getline(cin,s)){
		string t ="";
		for(int i=0; i<s.size(); i++){
			t+=m[s[i]];
		}
		string ans = "";
		for(int i=0; i<t.size(); i++){
			int j=i;
			string str ="";
			while(mm[str] ==  (char)0 && j<t.size()) str += t[j++];
			//cout<<mm[str]<<endl;
			if(mm[str] != 0) ans += mm[str];
			i=j-1;
		}
		cout<<ans<<endl;
	}

}