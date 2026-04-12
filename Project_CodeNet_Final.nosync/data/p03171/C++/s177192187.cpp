#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);
 
#define f first
#define s second
 
#define inf (int)1e9 + 7
 
#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
#define mp(x,y) make_pair(x,y)
 
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
 
#define pb push_back
#define ppb pop_back
 
#define bitcoin __builtin_popcount
 
#define endl "\n"
 
#define in(x) insert(x)
 
#define sz(x) (int)x.size()
 
#define all(x) x.begin(),x.end()
 
#define pw2(x) (1ll<<x) //2^x
 
#define forit(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
 
#define sqr(x) ((x) * 1ll * (x))
 
#define UpdateRandom srand (time(NULL));
 
using namespace std;
 
const int N = (int)3e3 + 7, MOD = (int)1e9 + 7;

int n;
int a[N];
ll dp[N][N][4];
bool was[N][N][4];

ll calc(int l,int r,int cur){
	if(l>r)return 0;
	if(was[l][r][cur])return dp[l][r][cur];
	was[l][r][cur]=1;
	if(cur == 1){
		dp[l][r][cur]=min(calc(l+1,r,(cur^1))-a[l],calc(l,r-1,(cur^1))-a[r]);
	}
	else{
		dp[l][r][cur]=max(calc(l+1,r,(cur^1))+a[l],calc(l,r-1,(cur^1))+a[r]);
	}
	return dp[l][r][cur];
}

int main(){
		
	NFS
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	cout << calc(1,n,0) << endl;

	ioi
}