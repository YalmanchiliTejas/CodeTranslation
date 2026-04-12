/// Code By t_bone_289 (Tushar Singh)
/// An Immature Programmer.... I'm still developing !!
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define endl '\n'
#define M 1000000007
#define error(x) cout << #x << " = " << x << endl;
#define pi 3.14159265358979323846
typedef long long ll;
typedef double d;
typedef long double ld;
template <typename T>
void ContainerError(T &v){cout<<"{";for(auto &x:v){cout<<x<<',';}cout<<"}"<<endl;return;}
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
ll mpow(ll base,ll exp){ll res=1;while(exp>0){if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return (res);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &x:v)
    {
        cin>>x;
    }
    vector<vector<ll> > dp(n,vector<ll>(n,0));
    for(ll sz=1;sz<=n;sz++)
    {
        ll i=0;
        ll j=sz-1;
        while(j<n)
        {
            if(sz==1)
            {
                dp[i][j]=v[i];
            }
            else if(sz==2)
            {
                dp[i][j] = max(v[i]-v[j],v[j]-v[i]);
            }
            else
            {
                ll x1 = v[i] + min(dp[i+1][j-1]-v[j],dp[i+2][j]-v[i+1]);
                ll x2 = v[j] + min(dp[i][j-2]-v[j-1],dp[i+1][j-1]-v[i]);
                dp[i][j] = max(x1,x2);
            }
            i++;
            j++;
        }
    }
    cout<<dp[0][n-1];
    return 0;
}

