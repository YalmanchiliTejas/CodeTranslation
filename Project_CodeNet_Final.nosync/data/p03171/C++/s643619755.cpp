#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,n)	for(ll i=0;i<(n);i++)
#define SZ(x) ((ll)x.size())
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define int ll
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll MOD = INT_MAX;
const double PI = acos(-1);

void openfile(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}
const int N = 3005;
int dp[N][N];
int a[N];

int func(int l,int r){
	if(dp[l][r] != 0)	return dp[l][r];
	if(r-l == 0)	return dp[l][r] = a[l];
	if(r-l == 1)	return dp[l][r] = max(a[l],a[r]);
	return dp[l][r] = 
		max(min(func(l+2,r), func(l+1,r-1)) + a[l],min(func(l+1,r-1),func(l,r-2)) + a[r]);
}

signed main(){
	IOS
	int n;	cin >> n;
	int sum = 0;
	rep(i,n)	cin >> a[i],sum += a[i];
	cout << func(0,n-1)*2 - sum << endl;


}
