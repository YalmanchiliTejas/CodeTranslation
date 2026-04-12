#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef long double ld;
#define A 1000000007
#define D 100000000000000ll
#define B 998244353ll
#define C 1000000000000000000ll
#define M 4000
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<pair<ll,ll>, null_type,greater<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define bs binary_search
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define ve vector
#define br break
#define PI acos(-1)
#define subt cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n" 

int main() 
{
    FAST;
    ll x=500000004ll,n=0;
    cin>>n;
    ve<ll> a(n);
    ll sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum1=(a[i]+sum1)%A;
        sum2=(sum2+((a[i]*a[i])%A))%A;
    }
    sum1=(sum1*sum1)%A;
    sum1=(sum1-sum2+A)%A;
    sum1=(sum1*x)%A;
    cout<<sum1;
    subt;
    return 0;
}