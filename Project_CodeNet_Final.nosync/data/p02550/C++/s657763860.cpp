/*   ꧁༒☬महाकाल☬༒꧂ ꧁༒ঔमहाकालঔ༒꧂
                   
                   ঔৣ۝महाकालᴳᵒᵈ۝ঔৣ            
 
 */ 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops"
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T, typename cmp=less<T>> using oset =tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long 
#define mod 1000000007
#define MOD 998244353
#define inf 100000000000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _it iterator
#define all(_x) _x.begin(),_x.end()
#define f first
#define s second
#define pb push_back
#define ar array
#define ld long double

void mahakal(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
}
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
// char c[4]={'D' , 'R' , 'U' , 'L'};
const ll maxN=3e5+5;
ll n , x , m ;
void solve(){
  cin>> n >> x >> m ;
  vector<ll> dp;
  set<ll> st ;
  dp.pb(x);
  st.insert(x);
  ll i;
  for(i=1;i<n ;i++){
      x = (x%m*x%m)%m ;
      if(st.find(x)!=st.end()){
        break;   
      }
      st.insert(x);
      dp.push_back(x);
    //   cerr<<x<<" ";
  }
  ll idx1=i , idx2;
  for(ll j=0;j<dp.size();j++){
      if(dp[j]==x){
        idx2=j;
      }
  }
   ll ans=0 , sum=0 , cnt=0, sum2=0 , sum1=0;
  for(ll i=0;i<dp.size(); i++){
     if(i<=idx1)sum2+=dp[i];
 }
 if(idx1>=n){
     cout<<sum2<<endl;
     return ;
 }
//   cerr<<idx1<<" "<<idx2<<endl;
  
  ll ps = idx1-idx2;
  ll ss = (n-i)/ps;
  ll rem = (n-idx1)%ps;
  for(ll i = idx2 ; i<dp.size();i++){
    sum+=dp[i];
    if(cnt<rem)sum1+=dp[i];
    cnt++;
  }
  ans = sum*ss + sum1 + sum2;
  cout<<ans<<endl;
}

int main(){
// 	mahakal();
	fast;
	ll t =1 ;
// 	cin>> t ; 
	while(t--)solve();
// 	cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
	return 0;
}
