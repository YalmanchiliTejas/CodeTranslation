#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define  ll long long

void solve(){

  ll n; cin>>n; 
  ll x= n*800;
  ll y= n/15;
  
  y*=200;
  cout<<x-y<<endl;
  }

int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

 ios_base::sync_with_stdio(0);
 cin.tie(0);

  int t =1;  /*cin>>t ;*/

  while(t--){
        solve();
  }

 return 0;
}
