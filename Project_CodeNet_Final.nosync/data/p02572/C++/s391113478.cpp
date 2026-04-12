#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define MAXX 999999999999999
#define PI 3.14159265358979323846
#define ep emplace_back
#define mk make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> PII;
typedef pair<lli,lli> PLL;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
//   freopen("input.txt","rt",stdin);

   lli n;
   cin>>n;
   
   vector<ulli> v(n+1,0),suff_sum(n+2,0);
   for(int i=1;i<=n;i++)
      cin>>v[i];
   
   for(int i=n;i>=1;i--)
      suff_sum[i] += (suff_sum[i+1]+v[i]);
   
   ulli ans = 0;
   for(int i=1;i<=n;i++)
   {
      ans += (((v[i]%M)*(suff_sum[i+1]%M))%M);
      ans %= M;
   }
   
   cout<<ans<<"\n";
}
