#include<bits/stdc++.h>
using namespace std;
 
typedef    long long          ll;
typedef    vector<long long>    vi; 
typedef    vector<vi>         vvi; 
typedef    pair<long,long>      ii; 
#define    sz(a)              long((a).size()) 
#define    pb                 push_back 
#define    mp                   make_pair
#define    all(c)             (c).begin(),(c).end() 
#define    tr(c,i)            for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define    present(c,x)       ((c).find(x) != (c).end()) 
#define    cpresent(c,x)      (find(all(c),x) != (c).end())  
#define    input(v,n)           for(ll i = 0 ; i<n ; i++) cin>>v[i]
#define    output(v,n)          for(ll i = 0 ; i<n ; i++) cout<<v[i]<<" "
#define    ff           first
#define    ss           second


ll mod = 1e9+7;

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,i;
    cin>>n;
    vi v(n);
    ll ans = 0;
    ll sum = 0;
    for(i=0;i<n;i++)
    {
      cin>>v[i];
      sum+=v[i];
      sum%=mod;
    }
    for(i=0;i<n;i++)
    {
      sum-=v[i];
      sum+=mod;
      sum%=mod;
      ans+=sum*v[i];
      ans%=mod;
    }

    cout<<ans<<"\n";

  return 0;
}