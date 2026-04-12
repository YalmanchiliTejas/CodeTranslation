#include <bits/stdc++.h>
using namespace std;

typedef int integer;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define lw lower_bound
#define fs first 
#define sd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll INF = 1e10;
const ld EPS = 1e-8;

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAXN = 3001;
const int K=20;

int n,m;
int a[MAXN];
int dp[MAXN][MAXN][2];

int solve(int i, int j,int t){
	if(i>j)return 0;
	int &r = dp[i][j][t];
	if(r!=-1)return r;
	r=0;
	if(t==0){
		r=max(a[i]+solve(i+1,j,1),a[j]+solve(i,j-1,1));
	}else{
		r=min(solve(i+1,j,0)-a[i],solve(i,j-1,0)-a[j]);
	}
	return r;
}

integer main(){
	cin>>n;
	mm(dp,-1);
	fore(i,0,n)cin>>a[i];
	int r = solve(0,n-1,0);
	cout<<r;
    return 0;
}

