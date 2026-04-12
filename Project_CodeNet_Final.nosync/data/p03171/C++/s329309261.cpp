#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ve vector
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define sz(a) (int)(a.size())
//using namespace __gnu_pbds;
using namespace std;

// // // functions: find_by_order  & order_of_key
// typedef tree<
// int,
// null_type,
// less<int>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int inf=(int)2e9;
const long long mod=1000000007; //1E9+7
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

ll powmod(ll a,ll p){
	ll ans=1;
	while(p){
		if(p&1) ans*=a;
		p/=2;a*=a; ans%=mod;a%=mod;
	}
	return ans;
}
ll mdinv(ll a){return powmod(a,mod-2); }

const int N=3e3+2;
int DP[N][N];
int v[N];
int p[N];

int sol(int l,int r){
	if(l>r) return 0;
	if(l==r) return v[l];
	if(DP[l][r]!=-1) return DP[l][r];
	int a=v[l]-sol(l+1,r)+p[r]-p[l];
	int b=v[r]-sol(l,r-1)+p[r-1]-p[l-1];
	return DP[l][r]=max(a,b);
}

signed main(){
	IOS
	memset(DP,-1,sizeof(DP));
	int n;cin>>n;
	forn(i,n){
		cin>>v[i+1];
		p[i+1]=p[i]+v[i+1];
	}
	int my=sol(1,n);
	int his=p[n]-my;
	cout<<my-his;
}
