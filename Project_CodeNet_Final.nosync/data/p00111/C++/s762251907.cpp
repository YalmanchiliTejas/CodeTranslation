#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#ifdef _DEBUG
#define DBG(n) n
#else
#define DBG(n)
#endif
#define INF         1e9
#define INFLL       1e18
#define EPS         1e-9
#define REP(i,n)    for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)   for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)   for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)  for(ll i=(n);i>0;--i)
#define REPC(i,obj) for(auto i:obj)
#define ALL(obj)    (obj).begin(),(obj).end()
#define SETP(n)     cout<<fixed<<setprecision(n)
using namespace std;
using ll = long long;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

signed main()
{
	map<string, char>mp;
	mp["101"] = ' ';
	mp["000000"] = '\'';
	mp["000011"] = ',';
	mp["10010001"] = '-';
	mp["010001"] = '.';
	mp["000001"] = '?';
	mp["100101"] = 'A';
	mp["10011010"] = 'B';
	mp["0101"] = 'C';
	mp["0001"] = 'D';
	mp["110"] = 'E';
	mp["01001"] = 'F';
	mp["10011011"] = 'G';
	mp["010000"] = 'H';
	mp["0111"] = 'I';
	mp["10011000"] = 'J';
	mp["0110"] = 'K';
	mp["00100"] = 'L';
	mp["10011001"] = 'M';
	mp["10011110"] = 'N';
	mp["00101"] = 'O';
	mp["111"] = 'P';
	mp["10011111"] = 'Q';
	mp["1000"] = 'R';
	mp["00110"] = 'S';
	mp["00111"] = 'T';
	mp["10011100"] = 'U';
	mp["10011101"] = 'V';
	mp["000010"] = 'W';
	mp["10010010"] = 'X';
	mp["10010011"] = 'Y';
	mp["10010000"] = 'Z';
	string inpt;
	while (getline(cin, inpt)) {
		string code;
		REPC(i, inpt) {
			if ('A' <= i && i <= 'Z')code += bitset<5>(i - 'A').to_string();
			else if (i == ' ')code += "11010";
			else if (i == '.')code += "11011";
			else if (i == ',')code += "11100";
			else if (i == '-')code += "11101";
			else if (i == '\'')code += "11110";
			else if (i == '?')code += "11111";
		}
		string ans;
		ll head = 0;
		REP1(i, code.length()) {
			string sub = code.substr(head, i - head);
			if (mp.count(sub) == 1) {
				ans += mp[sub];
				head = i;
			}
		}
		cout << ans << endl;
	}
}
