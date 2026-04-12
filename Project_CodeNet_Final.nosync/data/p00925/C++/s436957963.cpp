#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <time.h>
#include <cctype>
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FFOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) FOR(i,0,b)
#define RREP(i,b) FFOR(i,1,b)
#define PB push_back
#define F first
#define S second
#define BE(c) c.begin(),c.end()
using namespace std;
typedef long long LL;
typedef LL ut;
typedef long double ld;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef vector<ut> VI;
typedef pair<ut,pr> ppr;
typedef priority_queue<pr,Vpr, greater<pr> > PQ;
const int SIZE=1e+5+10;
const ut INF=1<<30;
const ld eps=1e-6;
const LL mod=1e+9 + 7;

vector<int> pp;
typedef string::const_iterator SC;

int number(SC& begin){
	int res = 0;
	
	while(isdigit(*begin)){
		res *= 10;
		res += *begin - '0';
		begin++;
	}
	
	return res;
}

// ?????????????¨??????????(int???)?????????
int term(SC& begin){
	int res = number(begin);
	
	while(1){
		if(*begin == '*'){
			begin++;
			res *= number(begin);
		}
		else{
			break;
		}
	}
	return res;
}

// ?¶????????????????
int expression(SC& begin){
	int res = term(begin);
	
	while(1){
		if(*begin == '+'){
			begin++;
			res += term(begin);
		}
		else{
			break;
		}
	}
	return res;
}

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	if(s.size() == 1){
		if((s[0] - '0') == n)
			cout << "U" << endl;
		else
			cout << "I" << endl;
		return 0;
	}
	bool mb = false, lb = false;
	bool plus = false;
	int m = s[0] - '0';
	FOR(i,1,s.size()){
		if(i % 2){
			plus = s[i] == '+';
		}
		else{
			if(plus)
				m += s[i] - '0';
			else
				m *= s[i] - '0';
		}
	}
	if(n == m)
		mb = true;
	SC begin = s.begin();
	int l = expression(begin);
	//cout << l << endl;
	if(n == l)
		lb = true;
	if(lb && mb){
		cout << "U" << endl;
	}
	else if(lb){
		cout << "M" << endl;
	}
	else if(mb){
		cout << "L" << endl;	
	}
	else{
		cout << "I" << endl;
	}
	return 0;
}