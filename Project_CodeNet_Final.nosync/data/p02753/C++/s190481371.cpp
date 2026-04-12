#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }	//最大公約数(Greatest Common Divisor)
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }			//最小公倍数(Least Common Multiple)


int main() {
	string s;
	cin >> s;

	if (s[0] == s[1] && s[1]==s[2])
		cout << "No" << endl;
	else
		cout << "Yes" << endl;




}