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

	ll a[n];
	rep(i,n) cin >> a[i];

	cout << a[n-1];
	for(int i = n-3;i>=0;i-=2)  cout << " " << a[i];
	if(n % 2 == 0){
		for(int i = 0;i<n;i+=2) cout << " " << a[i];
	}else{
		for(int i = 1;i<n;i+=2) cout << " " << a[i];
	}
	
	cout << endl;
}