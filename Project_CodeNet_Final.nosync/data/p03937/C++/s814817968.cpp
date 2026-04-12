#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define what_is(x) cerr << #x << " is " << x << endl
#define N 200005

#define newLine	printf("\n");

#define sll(X) scanf("%lld", &X);
#define pll(X) printf("%lld", X);
#define printAll(X, n)	for(int i=0;i<n;i++)	printf("%lld ", X[i]); newLine;
#define scanAll(X, n)	for(int i=0;i<n;i++)	scanf("%lld", &X[i]);

ll n, m;
vector< string > s;
ll ans = 0;
bool flag = 0;
void poo(ll x, ll y) {
	if(x == n-1 && y == m-1) {
		if(s[x][y] == '#')
			ans ++;
		return ;
	}
	if(x+1 < n && y+1 < m && s[x+1][y] == '#' && s[x][y+1] == '#')	{
		flag = 1;
		return ;
	}
	bool here = 0;
	if(x+1 < n && s[x+1][y] == '#') {
		here = 1;
		poo(x+1, y);
	}
	if(y+1 < m && s[x][y+1] == '#') {
		here = 1;
		poo(x, y+1);
	}
	// if(here == 0)	flag = 1;
	return ;
}

int main() {
	sll(n); sll(m);
	ll ct = 0;
	for(int i=0;i<n;i++) {
		string temp;
		cin>>temp;
		for(int j=0;j<m;j++) {
			ct += (temp[j] == '#');
		}
		s.push_back(temp);
	}
	if(ct == n + m - 1 && s[n-1][m-1]=='#') {
		cout<<"Possible\n";
	} else {
		cout<<"Impossible\n";
	}
	// poo(0, 0);
	/*if(ans == 1 && !flag) {
		cout<<"Possible\n";
	} else {
		cout<<"Impossible\n";
	}*/
	return 0;
}