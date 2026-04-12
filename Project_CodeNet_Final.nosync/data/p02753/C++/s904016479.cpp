#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define REP(i,a,b) for(ll i = ll(a); i < ll(b); i++)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	if(s == "AAA" || s == "BBB")
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}