#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define ff first
#define ss second
#define endl '\n'
#define MAX INT_MAX
#define MIN INT_MIN
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define pb push_back
#define sz(a) (int)((a).size())
#define all(a) a.begin(),a.end()
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define forn(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair< int,int > pii;



int32_t main()
{
    fast

   int test=1;
    //cin>>test;
  
   

  while(test--)
  {
    int n;
    cin>>n;

    vi a(n);
    forn(i,n)cin>>a[i];

   vi s(n,0);
   s[n-1]=a[n-1];
   for(int i=n-2;i>=0;i--)
   {
    s[i]=(a[i]+s[i+1])%mod;
   }

   int ans=0;
   for(int i=0;i<n-1;i++)
   {
    ans=(ans+a[i]*s[i+1])%mod;
   }

   cout<<ans;


// while ending
   }
  

return 0;
}