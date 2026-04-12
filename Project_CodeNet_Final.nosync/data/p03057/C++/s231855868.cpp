#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

ll n,m;
string s;
ll f[200010],rui[200010];

int main(){
    cin>>n>>m>>s;
    if(s[0]=='R'){
	for(int i=0;i<m;i++){
	    if(s[i]=='R')s[i]='B';
	    else s[i]='R';
	}
    }
    bool th=0;
    ll cnt=0,mi=1e17;
    bool fi=1; ll lead;
    for(int i=0;i<m;i++){
	if(s[i]=='R'){
	    if(fi)lead=cnt; fi=0;
	    th=1;
	    if(cnt%2==1)chmin(mi,cnt);
	    cnt=0;
	}
	else cnt++;
    }
    
    if(th==0){
	f[0]=f[1]=1;
	for(int i=2;i<n;i++){
	    f[i]=(f[i-1]+f[i-2])%mod;
	}
	ll ans=(f[n-2]*2+f[n-1])%mod;
	cout<<ans<<endl;
	return 0;
    }
    if(n%2==1){
	cout<<0<<endl;
	return 0;
    }
    
    if(lead%2==0)lead++;
    chmin(mi,lead);
    mi=(mi+1)/2;
    chmin(mi,n/2);
    f[0]=rui[0]=0;
    for(ll i=1;i<=mi;i++){
	f[i]=i;
    }
    for(int i=1;i<n/2;i++){
	mad(f[i],rui[i-1]);
	if(i-mi-1>=0)mad(f[i],-rui[i-mi-1]);
	rui[i]=(rui[i-1]+f[i])%mod;
    }
    ll ans=0;
    for(int i=1;i<=mi;i++)mad(ans,f[n/2-i]);
    //cout<<mi<<endl;
    //for(int i=0;i<n/2;i++)cout<<i<<":"<<f[i]<<endl;
    ans=ans*2%mod;
    if(mi==n/2)mad(ans,n);
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
}

