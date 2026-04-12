#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll sz=1e4+100;;
const ll mod=1e9+7;

ll dp[sz][100][3];
string str;
ll len,kick;

ll cholo(ll id,ll rem, bool bl)
{
    if(id>=len){
        if(rem==0) return 1ll;
        else return 0ll;
    }

    ll &ret=dp[id][rem][bl];
    if(~ret) return ret;

    ll last=(bl) ? (str[id]-'0') : 9;
    ll sum=0;

    for(ll i=0;i<=last;i++){
        if(i==last) sum=(sum + cholo(id+1,(rem + i)%kick,bl))%mod;
        else sum=(sum + cholo(id+1,(rem+ i)%kick,false))%mod;
    }

    return (ret=sum);
}

int main()
{
    ll n,m,p,q,x,y,i,j,k,l;

    cin>>str>>kick;
    memset(dp,-1,sizeof dp);
    len=str.length();

    ll ans=cholo(0,0,true);
    ans=(((ans-1ll)%mod)+mod)%mod;

    cout<<ans<<'\n';

}
