#include <bits/stdc++.h>
#include <iostream>	
#define pb push_back
#define mp make_pair
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
typedef long long ll;

const int inf = int(2e9);
const int mod = inf + 7;
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int a[n];
	int pref[n], suff[n];
	rep(i, n) cin >> a[i];
	pref[0] = a[0];
	suff[n - 1] = a[n - 1];
	for(int i = 1; i < n; ++i){
		pref[i] = max(pref[i - 1], a[i]);
	}
	int cnt = 1;
	for(int i = n - 1; i >= 1; --i){
		if(a[i] >= pref[i - 1]) cnt++;
	}
		cout << cnt;

}

int main()
{
	Red;
	solve();
	return 0;
}
