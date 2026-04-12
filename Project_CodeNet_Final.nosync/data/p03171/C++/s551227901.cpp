///   Journey to the End of earth   ///
/// Gunjan Kumar ///
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <functional> // for less 
// using namespace __gnu_pbds; 
using namespace std;
#define ll  long long
#define s(n) scanf("%d",&n)
#define ls(n) scanf("%lld",&n)
#define p(n) printf("%d",n)
// #define ln() printf("\n")
#define pln(n) printf("%d\n",n)
#define lpln(n) printf("%lld\n",n)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define rev(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define tc           ll t1; cin>>t1; while(t1--)
#define inp         ll n; cin>>n; ll arr[n]; rep(i,0,n) cin>>arr[i];
#define vect vector<ll>
#define sortv(v)       sort(v.begin(),v.end())
#define lower(v,n)    lower_bound(v.begin(),v.end(),n)-v.begin()
#define upper(v,n)    upper_bound(v.begin(),v.end(),n)-v.begin()
#define bitcount(n) __builtin_popcount(n)
#define ln <<endl
#define inf          LONG_MAX
#define ninf         LONG_MIN
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const   ll mod=1e9+7;
const ll N=3e2+5;



int main()
{

         
       int n;
       cin >> n;
       ll arr[n];
       rep(i,0,n)
       cin >> arr[i];
       ll  dp[n][n];
       memset(dp,0,sizeof(dp));
       for(int i=n-1;i>=0;i--)
       {
         for(int j=i;j<n;j++)
         {
          if(i==j)
            dp[i][j]=arr[i];
          else
             dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
         }
       }
       cout<<dp[0][n-1];

     return 0;
}

