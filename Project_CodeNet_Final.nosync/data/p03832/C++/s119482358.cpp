#include<bits/stdc++.h>
using namespace std;



#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define ll   long long 
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define S second
#define F first
#define die() return 0;
 
#define md          1000000007
#define fmd         998244353 
#define M           1011
#define N            18
ll exp(ll a,ll b){if(b<0)return 0;ll r=1;while(b){if(b&1)r=r*a%md,r%=md;a=a*a%md;b/=2;}return r;}

ll F[M],iv[M];
void prec(){
	F[0]=iv[0]=1;
	for(int i=1;i<M;++i){
		F[i]=F[i-1]*i%md;F[i]%=md;
		iv[i]=iv[i-1]*exp(i,md-2)%md;iv[i]%=md;
	}
}
ll chose(ll n,ll k){
	if(n<k)return 0;
	ll r=F[n];r=r*iv[k];r%=md;r=r*iv[n-k];return r%md;
}
ll bo(ll j,ll i){
	ll up=F[i*j];
	ll down=iv[i];
	// trace(down,up);
	down=exp(down,j);
	up=up*down%md;up%=md;
	up=up*iv[j];
	// trace(up,down);
	return up%md;
}

ll a,b,c,d;
ll dp[M][M];



ll f(ll i,ll n){
	if(n==0)return 1;
	if(i<a)return 0;
	if(dp[i][n]!=-1)return dp[i][n];
	ll &ans=dp[i][n];
	ans=0;
	ans=ans+f(i-1,n);
	for(ll j=c;n-j*i>=0&&j<=d;++j){
		ll p=f(i-1,n-i*j);
		// trace(i-1,n-i*j,i,j,n,p,bo(j,i));
		p=p*bo(j,i);
		p%=md;
		p=p*chose(n,i*j);p=p%md;
		ans+=p;ans%=md;
	}
	return ans;


}


int solve(){
    ll n,i,j,k,m,x,y,z;
    cin>>n>>a>>b>>c>>d;
    memset(dp,-1,sizeof(dp));
    ll p=f(b,n);
    cout<<p<<"\n";

    die();
}
 
 
int main(){
 
 
#ifndef ONLINE_JUDGE
    double _tBeg=clock();
#endif

     
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    t=1;;
    prec();
    // cin>>t;
 
    while(t--){

        solve();
    }
 
 
 
 


#ifndef ONLINE_JUDGE
    double _tEnd=clock();
    // printf("\ntotal time %.6f\n",(_tEnd-_tBeg)/CLOCKS_PER_SEC);
#endif
 
    die();
}