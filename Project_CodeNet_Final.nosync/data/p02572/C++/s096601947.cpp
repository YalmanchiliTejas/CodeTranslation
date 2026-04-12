#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree < int,  null_type,  less<int>,  rb_tree_tag,  tree_order_statistics_node_update > ordered_set;
typedef long long ll;
#define pb push_back
#define pi (acos(-1))
#define ull  unsigned long long
#define ld long double
#define all(v) v.begin(), v.end()
///freopen("input.txt","r",stdin);
///freopen("output.txt","w",stdout);
ll LCM(ll a, ll b)
{
    ll g = __gcd(a,b);
    return (a/g)*b ;
}
string numtostr(ll n)
{
    ostringstream str1 ;
    str1 << n ;
    return str1.str();
}
ll strtonum(string s)
{
    ll x ;
    stringstream str1(s);
    str1 >> x ;
    return x ;
}
#define mx 1000000007
int n,i;
ll s=0,sum=0,b=0;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
   ll a[n];
   for(i=0;i<n;++i)
    cin>>a[i];
   for(i=1;i<n;++i)
    s+=a[i];
    for(i=0;i<n;++i)
    {
        if(i==0)
          sum=((sum%mx)+((s%mx)*(a[i]%mx)))%mx;
          else
          {
              s-=a[i];
              sum=((sum%mx)+((s%mx)*(a[i]%mx)))%mx;
          }
    }
    cout<<sum<<'\n';
    return 0;
}
