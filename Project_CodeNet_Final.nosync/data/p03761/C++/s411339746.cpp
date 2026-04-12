#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
int inf=1e5+9;
int main(){
	int n;
	cin >> n;
	string s;
	int a[n][26];
	FOR(i,n) FOR(j,26) a[i][j]=0;
	FOR(i,n){
		cin >>s ;
		FOR(j,s.length()) a[i][s[j]-97]++;
	}
	int m[26];
	FOR(j,26) m[j]=inf;
	FOR(i,26){
		FOR(j,n){
			m[i]=min(a[j][i],m[i]);
		}
	}
	FOR(i,26){
		FOR(j,m[i])
			cout << (char)(i+97);
	}

	return 0;
}