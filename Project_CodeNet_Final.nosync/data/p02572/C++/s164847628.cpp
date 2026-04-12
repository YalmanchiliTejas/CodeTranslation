#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define pii pair<int,int>
#define pb(x) push_back(x)
#define lbound lower_bound
#define ubound upper_bound
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcountll(x)
#define heap_min priority_queue<int,vector<int>,greater<int>>
#define heap_max priority_queue<int>
#define precision(x) cout << setprecision(x) << fixed;
#define printv(v) for(auto p : v) cout << p << " ";
#define printa(a,n) for(int i = 0 ; i < n ; i++) cout << a[i] << " "; 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;


int32_t main()
{
   fast;
   #ifndef ONLINE_JUDGE
   freopen("goodluckin.txt","r",stdin);
   freopen("goodluckout.txt","w",stdout);
   #endif

   int n;
   cin >> n;
   int a[n];
   for(int i = 0 ; i< n ; i++){
      cin >> a[i];
   }  
   vector<int>suff(n,0);
   suff[n-1] = a[n-1];
   for(int i = n-2 ; i>=0 ; i--){
     suff[i] = a[i]+suff[i+1];
   }

   int ans = 0;
   for(int i = 0 ; i < n-1 ; i++){

     int curr = a[i];
     ans = ((ans%mod) + ( (curr%mod) * 1LL * (suff[i+1]%mod))%mod)%mod;
   }
   cout << ans;

}
