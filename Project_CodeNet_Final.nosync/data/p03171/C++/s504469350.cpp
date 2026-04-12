#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define PII pair<ll,ll>
#define VI  vector<ll>
#define VB  vector<bool>
#define VC vector<char>
#define VVI vector<vector<ll>>
#define VVC vector<vector<char>>
#define VS  vector<string>
#define VP  vector<PII>
#define lf(i,a,b) for(ll i=a;i<=b;i++)
#define lr(i,a,b) for(ll i=a;i>=b;i--)
#define lfl(i,v) for(ll i=0;i<v.size();i++)
#define lrl(i,v) for(ll i=(ll)(v.size())-1;i>=0;i--)
#define chk2(a,b) cout<<"check :  "<<a<<" "<<b<<endl
#define chk3(a,b,c) cout<<"check :  "<<a<<" "<<b<<" "<<c<<endl
#define chk4(a,b,c,d) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define chk5(a,b,c,d,e) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl
#define l_b(v,k)  lower_bound(v.begin(),v.end(),k)-v.begin()
#define u_b(v,k)  upper_bound(v.begin(),v.end(),k)-v.begin()
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define p_b push_back
#define p_f push_front
#define m_p make_pair
#define fir first
#define sec second
#define sz size()
ll n,m,k;
ll dp[3005][3005];
VI v;
ll fun(ll str,ll end)
    {   if(str>end)
            return 0;
        if(dp[str][end]!=-1)
            return dp[str][end];
        return dp[str][end]=max(v[str]+min(fun(str+1,end-1),fun(str+2,end)),v[end]+min(fun(str,end-2),fun(str+1,end-1)));
    }
int main() 
{   cin>>n;
    v=VI(n+1);
    memset(dp,-1,sizeof(dp));
    ll sum=0;
    lf(i,1,n)
    {   cin>>v[i];sum+=v[i];}
    cout<<fun(1,n)-(sum-fun(1,n))<<endl;
}