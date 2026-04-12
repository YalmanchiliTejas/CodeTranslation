#include "bits/stdc++.h"
using namespace std;

template <class... Args>
void gin(Args&&... args) { (cin >> ... >> args); }
#define dbg(var) cout<<#var<<"="<<var<<" "
#define nl cout<<"\n"
#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fa(v) for(auto &i:v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
//#define int long long

void solve(){
 int n; gin(n);
 cout << (n >= 30 ? "Yes":"No");

}
int32_t main()
{
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   // int tst; cin >> tst; while(tst--)
   {
   	solve();
   }
}