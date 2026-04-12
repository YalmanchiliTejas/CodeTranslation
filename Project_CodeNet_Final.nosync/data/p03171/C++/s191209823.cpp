#include <bits/stdc++.h>
#include <cstdio>
#include <chrono>
#include <random>
using namespace std;

#define DRACARYS ios_base::sync_with_stdio(false);cin.tie(NULL);cin.exceptions(cin.failbit);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, -1, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define PI 3.14159265
const long long int MAXN = 3e3+10;
const long long int MINN = 1e5+10;
const long long int inf = 1e18+7;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; 
typedef stack<int> st;

ll n,a[MAXN],dp[MAXN][MAXN],s;

ll foo(int l, int r){
	if(l+1==r){
		dp[l][r]=max(a[l],a[r]);
		return dp[l][r];
	}
	if(l==r){
		dp[l][r]=a[l];
		return dp[l][r];
	}
	ll x,y,z;
	x=(dp[l+1][r-1]==-1?foo(l+1,r-1):dp[l+1][r-1]);
	y=(dp[l+2][r]==-1?foo(l+2,r):dp[l+2][r]);
	z=(dp[l][r-2]==-1?foo(l,r-2):dp[l][r-2]);
	dp[l][r]=max(a[l]+min(x,y),a[r]+min(x,z));
	return dp[l][r];
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    DRACARYS    
    cin>>n;
    fill(dp);
    repA(i,1,n) cin>>a[i],s+=a[i];
    cout<<2*foo(1,n)-s<<endl;
    return 0;
}

