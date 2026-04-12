#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
//#define int   long long
#define ll   long long
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define vl vector<long long>
#define inf (1LL<<61)
#define vi vector<int>
#define vii vector< vector<int> >
#define vll vector< vector<long long> >
#define vpi vector< pair<int,int> >
#define vpl vector< pair<ll,ll> >
#define viii vector< vector<vector<int> > >
typedef pair<pair<int, int>,int> P;
#define cd complex<double>
#define PI 4*atan(1)
#define mod %1000000007
#define pi 3.14159265358979323846//20 decimals
#define ld long double
#define M 100000008

ll n;
ll a[3001];
ll dp[3001][3001];
ll o[3001][3001];

void pro(ll i, ll j)
{
	if((i - j + 1) == 2)
		dp[i][j] = abs(a[i] - a[j]);
	else if(i == j)
		dp[i][j] = a[i];
	else
	{
		ll t1, t2;
		if(o[i+1][j] == 0)
			pro(i+1, j);
		t1 = a[i] - dp[i+1][j];
		if(o[i][j-1] == 0)
			pro(i, j-1);
		t2 = a[j] - dp[i][j-1];
		dp[i][j] = max(t1, t2);
	}
	o[i][j] = 1;
}

int main()
{
	FAST;
	ll i, j;
	cin >> n;
	fr(i,0,n)
		cin >> a[i];
	pro(0, n-1);
	cout << dp[0][n-1];
}
