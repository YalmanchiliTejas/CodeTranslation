#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define pii pair<int,int>
#define pll pair<ll, ll>
#define forn(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007

int n;
int a[5000];
ll ds[4000][4000][2];

ll dp(int s, int e, int p){
	if(s > e) return 0;
	if(ds[s][e][p] != -1) return ds[s][e][p];
	ll &ans = ds[s][e][p];
	if(p == 0) ans = max(a[s] + dp(s + 1, e, 1), a[e] + dp(s, e - 1, 1));
	else ans = min( - a[s] + dp(s + 1, e, 0),  - a[e] + dp(s, e - 1, 0));
	return ans;
}
 
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	forn(i, 0, n - 1){
		cin >> a[i];
	}
	memset(ds, -1, sizeof(ds));
	cout << dp(0, n - 1, 0) << "\n";
	return 0;
}