/**
 *	@file: A.cpp
 *	@author: Huy Le
 *	@created: 08/02/2020 19:13:59
**/


#include<bits/stdc++.h>
using namespace std;

//***---***---***---***---***---***---BEGIN USELESS CODE---***---***---***---***---***---***//

#define ll long long
#define ld long double
const char newl = '\n';

template<class T> void read(vector<T>& vt);
template<class T>
void read(T& args) { cin >> args; }
template<class A, class... B >
void read(A& argc, B&... argv) {
	read(argc);
	read(argv...);
}
template<class T>
void read(vector<T>& vt) {
	for(auto &a : vt)
		read(a);
}

string to_string(bool bo) { return (bo ? "true" : "false"); }
string to_string(char c) { return string(1, c); }
string to_string(const char* str) { return string(str);}
string to_string(string str) { return str; }
template<class T>
string to_string(T vt) {
	bool ft = 1;
	string res;
	for(auto &a : vt) {
		if(!ft)
			res += ' ';
		ft = 0;
		res += to_string(a);
	}
	return res;
}
string to_string(vector<bool> vt) {
	string res;
	bool ft = 1;
	for(int i = 0; i < (int)vt.size(); ++i) {
		if(!ft)
			res += ' ';
		ft = 0;
		res += char('0' + vt[i]);
	}
	return res;
}

template<class T>
void write(T args) { cout << to_string(args); }
template<class A, class... B>
void write(const A argc, const B... argv) {
	write(argc);
	write(argv...);
}

void print() { write(newl); }
template<class A, class... B>
void print(const A argc, const B... argv) {
	write(argc);
	if(sizeof...(argv))
		write(' ');
	print(argv...);
}

void DEBUGLOCAL() { cerr << ")" << newl; }
template<class A, class... B> 
void DEBUGLOCAL(A argc, B... argv) {
	cerr << to_string(argc);
	if(sizeof...(argv))
		cerr << ", ";
	DEBUGLOCAL(argv...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") [" << __FUNCTION__ << "] -> (" << #__VA_ARGS__ << "): (",DEBUGLOCAL(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

//***---***---***---***---***---***---END USELESS CODE---***---***---***---***---***---***//

int ts;
int n;

void solve() {
	read(n);
	print(n >= 30 ? "Yes" : "No");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//read(ts);
	//while(ts--)
		solve();
}
