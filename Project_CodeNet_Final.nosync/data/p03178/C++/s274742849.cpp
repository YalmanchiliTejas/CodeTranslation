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
ll n,m,k,d;
string s;
ll dp[10005][105][2];
ll power(ll x,  ll y,  ll m) 
{   if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
} 



ll fun(ll ind,ll str,ll rem)
    {   if(ind>=n)
        {   if(rem%d==0)
                return 1;
            else
                return 0;
        }
        if(dp[ind][rem][str]!=-1)
            return dp[ind][rem][str];
        ll mx=str?s[ind]-'0':9;
        ll sum=0;
        lf(i,0,mx)
        {   ll remn=(i+rem)%d;
            if(i==mx)
            {   sum=(sum+fun(ind+1,str,remn))%mod;
            }
            else
            {   sum=(sum+fun(ind+1,0,remn))%mod;
            }
        }
        return dp[ind][rem][str]=sum;
    }
int main() 
{   cin>>s;
    cin>>d;
    n=s.length();
    memset(dp,-1,sizeof(dp));
    cout<<(fun(0,1,0)-1+mod)%mod<<endl;
}