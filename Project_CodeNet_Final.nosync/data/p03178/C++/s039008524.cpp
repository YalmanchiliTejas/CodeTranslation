#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define T ll
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

ll mexp(ll a, ll b, ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1) ans=ans*a%m;
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

const int N = 10005;

int dp[N][100][2];
string s;
int d;

int solve(int pos, int sum, bool tight){
	if(pos==sz(s)){
		if(sum==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	int &res = dp[pos][sum][tight];
	if(res!=-1 && tight==0){
		return res;
	}
	int lim=9;
	if(tight){
		lim=s[pos]-'0';
	}
	int ans=0;
	FOR(i,0,lim){
		bool next_tight=tight;
		if(s[pos]-'0'!=i){
			next_tight=0;
		}
		ans=(ans+solve(pos+1,(sum+i)%d,next_tight))%MOD;
	}
	return res=ans;
}

int main(){
    IOS
    memset(dp,-1,sizeof(dp));
    cin>>s>>d;
    cout<<(solve(0,0,1)-1+MOD)%MOD;
    
    return 0;
}