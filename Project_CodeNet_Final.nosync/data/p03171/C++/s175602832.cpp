#pragma comment(linker, "/stack:200000000")

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define int long long
#define ull unsigned long long
#define ld long double
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) return cout<<a,0;

using namespace std;

const int N = 4e3 + 123;

int n , k , a[4000] ;
bool was[N][N] ;
int dp[N][N];
int get(int l , int r){
	if(l == r)
		return a[l];
	if(r - l == 1){
		return max(a[l] , a[r]);
	}
	if(was[l][r])
		return dp[l][r];
	int tmp1 = a[l] + min(get(l + 1 , r - 1) , get(l + 2 , r));
	int tmp2 = a[r] + min(get(l + 1 , r - 1) , get(l , r - 2));
	
	was[l][r] = 1;
	dp[l][r] = max(tmp1 , tmp2);
	return dp[l][r];
}
main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n;
	int sum = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		sum += a[i];
	}
	int tmp = get(1 , n);
	cout << tmp - (sum - tmp);
}