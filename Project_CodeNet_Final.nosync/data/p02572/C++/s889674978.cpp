#include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
#include <fstream>
#include <climits>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  int INF = INT_MAX;
  ll mod = 1000000007;
  // lld PI = 3.141592653;
 


void solve(){
  
int n;
cin>>n;
vector<int> a(n);
for (int i = 0;i<n;i++) cin>>a[i];
vector<ll> sub(n);
sub[n-1] = a[n-1];
for (int i = n-2;i>=0;i--) sub[i] = (sub[i+1] + a[i])%mod;
ll ans = 0;
for (int i = 0;i<n-1;i++){
  ans= (ans+ (a[i]*sub[i+1])%mod)%mod;
}
cout<<ans<<"\n";
}

  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    while(q--) solve();

}