#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

using namespace std;

typedef long long ll;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pb_ds;

#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define pi pair<int,int>
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define mod 1000000007
#define pai acos(-1)
#define N 200005

ll ar[N],prefix[N];

int main ()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;cin>>n;
   for(int i=1;i<=n;i++){
      cin>>ar[i];
      prefix[i]=(prefix[i-1]+ar[i])%mod;
   }
   ll ans=0;
   for(int i=2;i<=n;i++){
      ll sum=(prefix[n]-prefix[i-1]+mod)%mod;
      ans=(ans+((ar[i-1]*sum)%mod))%mod;
   }
   cout<<ans<<"\n";
   return 0;
}

