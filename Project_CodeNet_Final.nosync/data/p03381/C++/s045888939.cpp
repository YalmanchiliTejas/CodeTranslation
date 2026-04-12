#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int x[n];
	int y[n];
	rep(i,n){
		cin >> x[i];
		y[i] = x[i];
	} 

	sort(y,y+n);

	rep(i,n){
		cout << (x[i] < y[n/2] ? y[n/2] : y[n/2-1]) << endl;
	}
}