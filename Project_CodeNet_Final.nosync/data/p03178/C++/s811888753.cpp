#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define fi first
#define se second
#define endl "\n"
#define all(v) v.begin(),v.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define go_t int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // order_of_key
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf = 0x3f3f3f3f3f3f3f3fll;//4x10e18
const int maxx = 3000000 , mod = 1000000007;
#define PI 3.14159265
ll dp[10005][105][2];
vector<int>num;
int n,d;
ll solve(int idx,int rem,int less)
{
    if(idx>=num.size())return (rem==0);
    ll &ans = dp[idx][rem][less];
    if(ans!=-1)
        return ans;
    ans = 0;
    if(less==0)
    {
        for(int i=0;i<=num[idx];i++)
        {
            ans+=solve(idx+1,(rem-i+d)%d,less+(i<num[idx]));
            ans%=mod;
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            ans+=solve(idx+1,(rem-i+d)%d,1);
            ans%=mod;
        }
    }
    ans%=mod;
    return ans;
}
int main()
{
    fastio;
    string s;
    cin>>s>>d;
    num.clear();
    set_ar(dp,-1);
    for(char c : s)
    {
        num.pb(c-'0');
    }
    n = s.size();
    cout<<(solve(0,0,0)-1+mod)%mod<<endl;
    return 0;
}
