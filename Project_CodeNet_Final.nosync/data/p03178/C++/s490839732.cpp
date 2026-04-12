//雪花飄飄北風嘯嘯
//天地一片蒼茫

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;

string s;
int k;

int memo[100005][105];
int dp(int i,int curr){
	if (i==sz(s)) return (curr==0);
	if (memo[i][curr]!=-1) return memo[i][curr];
	
	int res=0;
	rep(x,0,10){
		res=(res+dp(i+1,(curr+x)%k))%MOD;
	}
	
	return memo[i][curr]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(memo,-1,sizeof(memo));
	
	cin>>s;
	cin>>k;
	
	int curr=0;
	int ans=0;
	rep(x,0,sz(s)){
		int val=s[x]-'0';
		
		rep(y,0,val){
			//cout<<x+1<<" "<<(curr+y)%k<<" "<<dp(x+1,(curr+y)%k)<<endl;
			ans=(ans+dp(x+1,(curr+y)%k))%MOD;
		}
		curr=(curr+val)%k;
	}
	
	if (curr==0) ans++;
	ans=(ans-1+MOD)%MOD;
	
	cout<<ans<<endl;
}
