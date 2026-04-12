#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pii pair <int,int>
#define pll pair <ll,ll>
#define testcase() int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define vll vector <ll>
#define all(v) v.begin(),v.end()

ll M = 1e9 + 7;
double pi = acos(-1.0);
ll powerm(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x)%M; y=y>>1; x=(x*x)%M;} return res%M; }
ll power(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x); y=y>>1; x=(x*x);} return res; }
ll max3(ll a,ll b,ll c){ return max( max(a,b),c ); }
ll gcd(ll a,ll b){if(b>a)return gcd(b,a); if(b==0)return a; return gcd(b,a%b);}

const int N = 3005;
ll dp[N][N];
ll a[N];

ll solve(int st,int en)
{
    if(st>en) return 0;
    if(st==en){ dp[st][en] = a[st]; return a[st]; }
    if(dp[st][en]>-3e9) return dp[st][en];
    dp[st][en] = max( a[st] - solve(st+1,en) , a[en] - solve(st,en-1) );
    return dp[st][en];
}

int main() {
	
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	int n; cin>>n;
	forn(i,n) cin>>a[i];
	forn(i,N) forn(j,N) dp[i][j] = -3e9;
	cout<<solve(0,n-1);
	
	return 0;
}
