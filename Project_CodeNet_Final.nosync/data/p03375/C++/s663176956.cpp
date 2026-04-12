#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mod 1000000007
//#define mad(a,b) a=(a+b)%mod
#define N 200010
ll n,mo;
void mad(ll &a,ll b){
    a=(a+b)%mo;
}
ll po(ll x,ll y,ll m){
    if(y<0)return 0;
    ll res=1;
    for(;y;y>>=1){
	if(y&1)res=res*x%m;
	x=x*x%m;
    }
    return res;
}
ll dp[3010][3010],nck[3010][3010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>mo;
    
    nck[0][0]=1;
    for(int i=0;i<3010;i++)for(int j=0;j<3010;j++){
	nck[i][j]=0;
	if(i==0&&j==0)nck[i][j]=1;
	if(i)mad(nck[i][j],nck[i-1][j]);
	if(j)mad(nck[i][j],nck[i][j-1]);
    }
    
    for(int i=0;i<3010;i++)for(int j=0;j<3010;j++)dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<=n;i++)for(int j=0;j<=i;j++){
	mad(dp[i+1][j],dp[i][j]*(j+1));
	mad(dp[i+1][j+1],dp[i][j]);
	//cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
    }
    
    ll ans=0;
    for(int k=0;k<=n;k++){
	ll res=0;
	ll kei1=1,inc1=po(2,n-k,mo);
	ll kei2=po(2,po(2,n-k,mo-1),mo);
	for(int i=0;i<=k;i++){
	    
	    //ll cur=dp[k][i]*po(2,i*(n-k),mo)%mo;
	    ll cur=dp[k][i]*kei1%mo; kei1=kei1*inc1%mo;
	    
	    //cur=cur*po(2,po(2,n-k,mo-1),mo)%mo;
	    cur=cur*kei2%mo;
	    
	    mad(res,cur);
	    //cout<<"k="<<k<<" i="<<i<<":"<<cur<<endl;
	}
	//cout<<"#"<<k<<" "<<res<<" "<<nck[n-k][k]<<endl;
	if(k%2==0)mad(ans,+res*nck[n-k][k]);
	if(k%2==1)mad(ans,-res*nck[n-k][k]);
    }
    if(ans<0)ans+=mo;
    cout<<ans<<endl;
}


