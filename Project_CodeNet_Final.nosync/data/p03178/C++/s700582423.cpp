#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll          long long
#define pb          push_back
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define rs(v,n)     v.resize(n)
#define hell        1000000007
#define peak        9123372036854775807
#define pii         acos(-1)
#define clr(a,x)    memset(a,x,sizeof(a))
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ordered_set tree<ll int, null_type,less<ll int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
template<class x,class y> x sum(x a,y b){return a+b;}
template<class x,class y> x mul(x a,y b){return a*b;}
template<class x,class y> x sub(x a,y b){return a-b;}
template<class x,class y> x divi(x a,y b){return a/b;}

template<class x,class y>
istream &operator>>(istream &in,pair<x,y> &p) 
{ 
    in>>p.F>>p.S;
    return in;
}
template<class x>
istream &operator>>(istream &in,vector<x> &v) 
{
    for(auto& i:v)
        in>>i;
    return in;
}
template<class x,class y>
ostream &operator<<(ostream &out,pair<x,y> &p) 
{ 
    out<<"("<<p.F<<","<<p.S<<") ";
    return out; 
}
template<class x>
ostream &operator<<(ostream &out,vector<x> &v) 
{ 
    out<<v.size()<<endl;
    for(auto i:v)
        out<<i<<" ";
    out<<endl;
    return out; 
}
#define N  1000005
ll k;
ll dp[10004][10][102];
ll solve(ll z,ll d,ll m)
{
    m=m%k;
    if(dp[z][d][m]!=-1)
        return dp[z][d][m];
    if(z==0&&d==0)
    {
        return 0;
    }
    if(z==0)
    {
        ll ans=solve(z,d-1,m);
        if(d%k==m)
            ans++;
        ans%=hell;
        dp[z][d][m]=ans;
        return dp[z][d][m];
    }
    if(d==0)
    {
        ll ans=solve(z-1,9,(m%k+k)%k);
        ans=(ans+solve(z-1,0,(m-(9)%k+k)%k))%hell;
        dp[z][d][m]=ans;
        return ans;
    }
    ll ans=0;
    if(d!=1)
        ans=solve(z,d-1,m);
    ans=(ans+solve(z,0,(m-(d-1)%k+k)%k))%hell;
    if(d%k==m)
        ans=(ans+1)%hell;
    dp[z][d][m]=ans;
    return ans;
}
int main()
{
    ios;
    ll tt=1;
    // cin>>tt;
    while(tt--)
    {
        ll i,j,l,m,n;
        string s;
        cin>>s>>k;
        clr(dp,-1);
        dp[0][0][0]=0;
        n=s.size();
        ll ans=0;
        ll x=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')
                continue;
            solve(n-1-i,s[i]-48,(k-x)%k);
            ans=(ans+dp[n-1-i][s[i]-48][(k-x)%k])%hell;
            x=(x+s[i]-48)%k;
        }
        cout<<ans;
    }
    return 0;
}