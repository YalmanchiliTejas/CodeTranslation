#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int maxn=2e5+100;

int num[110],n,k;
ll dp[110][110][2];
ll f(int p,int tot,bool _0){
    //cout<<"p  :  "<<p<<"  tot  "<<tot<<"  _0 "<<_0<<endl;
    if(p==n) return tot==k;
    //if(tot>k) return 0;
    if (~dp[n-p][tot][_0]) return dp[n-p][tot][_0];
    ll res=0;int lim=!_0?num[p]:9;
    for(int i=0;i<=lim;i++)
        res+=f(p+1,tot+(i==0?0:1),_0||i!=lim);
    //if(p==1&&!tot&&_0)
    //cout<<res<<endl;
    return dp[n-p][tot][_0]=res;
}

int main()
{
    string s;
    cin>>s;
    scanf("%d",&k);
    n=s.size();
    for(int i=0;i<n;i++)
        num[i]=s[i]-'0';
    memset(dp,-1,sizeof(dp));
    ll ans=f(0,0,0);
    cout<<ans;
    return 0;
}
/*

*/
