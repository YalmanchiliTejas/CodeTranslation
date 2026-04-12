#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll n,s;
ll a[3030];
ll MOD=998244353;
ll dp[3030][3030];

ll f(ll x, ll y){
	if(y<0)return 0;
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(y==a[x]){
		r=x+1;
		if(x>0)r+=f(x-1,y),r%=MOD;
		return r;
	}
	if(x==0){
		return r=0;
	}
	/*if(y==s){
		r=(f(x-1,y-a[x])*(n-x))%MOD;
		return r;
	}else{*/
		r=(f(x-1,y)+f(x-1,y-a[x]))%MOD;
	//	cout<<x<<" "<<y<<" "<<r<<"\n";
		return r;
	//}
}

int main(){FIN;
	cin>>n>>s;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	ll res=0;
	fore(i,0,n)res+=f(i,s),res%=MOD;
	cout<<res;
	return 0;
}