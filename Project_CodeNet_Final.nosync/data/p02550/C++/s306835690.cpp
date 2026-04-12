////////////////////////    W H I T E C L O U D    ////////////////////////
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main()
{
    FAST();
    ll n,i,x,mod,ans,sum,cum[100004],rpt_elmnt,e,s,rpt_sum,baki,q,rem;
    map<ll,ll>mp;
    cin>>n>>x>>mod;
    cum[1]=sum=x;
    cum[0]=0;
    mp.insert({x,1});
    bool test=false;
    for(i=2; i<=1e5+4; i++)
    {
        if(i>n)break;
        x=(x*x)%mod;
        if(mp.count(x)==1)
        {
            test=true;
            s=mp[x];e=i-1;break;
        }
        mp.insert({x,i});
        sum+=x;
        cum[i]=sum;
    }
    rpt_sum=cum[e]-cum[s-1];
    rpt_elmnt=e-s+1;
    baki=n-e;
    q=baki/rpt_elmnt;
    rem=baki%rpt_elmnt;
    ans=sum;
    if(test)
    ans+=(q*rpt_sum)+cum[s+rem-1]-cum[s-1];
    cout<<ans<<endl;



    return 0;
}





