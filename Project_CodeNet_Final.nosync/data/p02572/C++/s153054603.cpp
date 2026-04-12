#include<bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using namespace std;
void solve() {
   int n;
   cin>>n;
   int arr[n];
   int sum[n]={0};
   for(int i=0;i<n;++i){
       cin>>arr[i];
       if(i==0) sum[i]=arr[0];
       else sum[i]=sum[i-1]+arr[i];
   }
   int ans=0;
   for(int i=1;i<n;++i){
       ans+=((arr[i]%1000000007)*(sum[i-1]%1000000007))%1000000007;
   }
   cout<<ans%1000000007;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
