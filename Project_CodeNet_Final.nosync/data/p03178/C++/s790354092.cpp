#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

string s;ll n,ans,d,md=1e9+7,a[10004],dp[10004][111];

ll solve(ll i,ll sum){
    if(i==n)return (sum==0);
    ll &ret=dp[i][sum];
    if(ret!=-1)return ret;
    ret=0;
    for(ll j=0;j<10;j++){
        ret=(ret+solve(i+1,(sum+j)%d))%md;
    }
    return ret;
}
int main(){
    cin>>s>>d;
    n=s.size();
    for(ll i=0;i<n;i++){
        a[i]=s[i]-'0';
        //cout<<a[i]<<' ';
    }
    //cout<<endl;

    memset(dp,-1,sizeof dp);
    ll sum=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<a[i];j++){
            ans=(ans+solve(i+1,(sum+j)%d))%md;
        }
        sum=(sum+a[i])%d;
    }

    ans=(ans-1+md+(sum==0))%md;
    cout<<ans<<endl;
    return 0;
}
