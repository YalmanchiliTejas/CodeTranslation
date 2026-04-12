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

int DP[10004][102][2];
string s; //reverse
int d;
int sol(int i,int r,int less){
	if(i<0) return r==0;
	if(DP[i][r][less]!=-1) return DP[i][r][less];
	int h=s[i]-'0';
	int ans=0;
	forn(x,10){
		if(less==0 && x>h) break;
		int nr=r+x;nr%=d;
		ans+=sol(i-1,nr,less|(x<h));
		if(ans>=mod) ans-=mod;
	}
	return DP[i][r][less]=ans;
}

signed main(){
	IOS
	cin>>s;reverse(all(s));
	cin>>d;
	memset(DP,-1,sizeof(DP));
	cout<<(((sol(sz(s)-1,0,0)-1)%mod+mod)%mod);
}
