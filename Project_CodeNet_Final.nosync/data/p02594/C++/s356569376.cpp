#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
typedef long double db;
#define pb push_back
#define mp make_pair
#define np(str) next_permutation(str.begin(),str.end())
#define ub(v,val) upper_bound(v.begin(),v.end(),val)
#define lb(v,val) lower_bound(v.begin(),v.end(),val)
#define sortv(vec) sort(vec.begin(),vec.end())
#define rev(p) reverse(p.begin(),p.end());
#define v vector
#define PI 3.1415926535
#define len length()
#define repc(i,s,e) for(ll i=s;i<e;i++)
#define fi first
#define se second
#define mset(a,val) memset(a,val,sizeof(a));
#define mt make_tuple
#define repr(i,n) for( i=n-1;i>=0;i--)
#define rep(i,n) for( i=0;i<n;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int M = 1e8 ;
ll INF = 1e12;

ll n, m;

int main() {
	// your code goes here
	IOS;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll i, j, t, k, x, y, z,  N;
	cin >> x;
	if (x >= 30)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}