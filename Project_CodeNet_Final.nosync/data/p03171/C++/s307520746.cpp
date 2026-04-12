#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define ll long long

#define MOD 1000000007
typedef pair<int, int> pii;
// typedef vector<int> vi;
// typedef vector<pii> vpi;
// typedef vector<vi> vvi;
// typedef long long i64;
// typedef vector<i64> vi64;
// typedef vector<vi64> vvi64;
// typedef pair<i64, i64> pi64;
// typedef double ld;
typedef  long long ui64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
// ui64 mx=1000*1000*1000+3;
// ui64 dp[mx];
ui64 dp[3003][3003];
ui64 arr[3003];

int main()
{
ui64 n,sum=0;
cin>>n;
forn(i,n)
{
cin>>arr[i];
sum+=arr[i];
}
forn(d,n)
{
for(int i=0,j=d;i<n-d;i++,j++)
	{
		if(i==j){
			dp[i][j]=arr[i];
			continue;}
			if(i>j)
			{
				break;
			}
			if(j<i+2)
			dp[i][j]=max(arr[i],arr[j]);
else
{
	dp[i][j]=max(arr[j]+min(dp[i][j-2],dp[i+1][j-1]),arr[i]+min(dp[i+2][j],dp[i+1][j-1]));
}

	}
}

cout<<2*dp[0][n-1]-sum;

return 0;
}
