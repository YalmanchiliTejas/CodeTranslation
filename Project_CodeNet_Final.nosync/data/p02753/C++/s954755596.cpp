#include<bits/stdc++.h>
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
#define pb push_back
#define popb pop_back
#define si size()
#define be begin()
#define en end()
#define le length()
#define mp make_pair 
#define mt make_tuple
#define fi
#define se second
 
#define forz(i,n) for(long long int i=0;i<n;i++)
#define deci(n)  fixed<<setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n)  __builtin_ctz(n)
#define mod 1000000007
#define mod2 998244353
#define kira ios::sync_with_stdio(0), cin.tie(0),cout.tie(0) 
 
using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s== "AAA" || s== "BBB")
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes"<< endl;
	}
	return 0;
}
