#include "bits/stdc++.h"
using namespace std;
#define dbg(var) cout<<#var<<"="<<var<<" "
#define nl cout<<"\n"
#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fa(v) for(auto &i:v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define int long long
const int mod = 1e9 + 7;
int32_t main()
{
   int n; cin >> n;
   int sm = 0;
   int prod = 0;
   fr(_,n){
   	int x; cin >> x;

   	prod += x * sm;
   	prod %= mod;
   	sm += x; sm %= mod;
   	// dbg(prod);dbg(sm);nl;
   }
   cout << prod;

}