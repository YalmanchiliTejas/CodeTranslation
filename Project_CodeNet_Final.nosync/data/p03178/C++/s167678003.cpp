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

const ll MOD=1000000007;
string s; ll k;

ll dp[10004][105][2];

ll f(ll x, ll y, ll z){
	ll &r=dp[x][y][z];
	if(r>=0)return r;
	if(x==SZ(s)){
		r=(y==0); return r;
	}
	if(z==0){
		r=0;
		fore(i,0,10){
			r+=f(x+1,(y+i)%k,0);
			if(r>MOD)r-=MOD;
		}
		return r;
	}
	r=0;
	fore(i,0,10){
		if(i<s[x]-'0')r+=f(x+1,(y+i)%k,0);
		if(i==s[x]-'0')r+=f(x+1,(y+i)%k,1);
		if(r>MOD)r-=MOD;
	}
	return r;
}

int main(){FIN;
	cin>>s>>k;
	mset(dp,-1);
	cout<<(f(0,0,1)+MOD-1)%MOD;
	return 0;
}