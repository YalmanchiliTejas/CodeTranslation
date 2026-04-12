#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
signed main()
{
   int n;
   cin>>n;
   int pre=0,ans=0;
   for(int i=0;i<n;i++)
   {
    int x;
    cin>>x;
    ans=(ans+pre*x)%mod;
    pre=(pre+x)%mod;
   }
   cout<<ans<<endl;
	return 0;
}
