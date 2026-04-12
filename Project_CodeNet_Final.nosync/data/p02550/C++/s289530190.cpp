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
  ll mod = 998244353;
  // lld PI = 3.141592653;



ll power(ll a, ll b){
 ll result = 1;
 while (b>0){
   if (b%2==1) result *= a;
   a*=a;
   b/=2;
 }
 return result;
}





  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
      ll n,x,m;
      cin>>n>>x>>m;
      vector<int> seen(m);
      int ind = 1;
      ll now = x;
      seen[now] = 1;
      ind++;
      ll ans = 0;
      vector<ll> pref;
      pref.push_back(0);
      pref.push_back(x);
      now = power(now, 2) % m;
      if (seen[now]){
        cout<< n * now<<"\n";
        return 0;
      }
      while (seen[now] == 0 && ind<=n){
        seen[now] = ind;
        pref.push_back(pref[pref.size()-1] + now);
        ind++;
       now = power(now, 2) % m;

      }
      if (ind - 1 == n){
        ans = pref[pref.size()-1];
        cout<<ans<<"\n";
        return 0;
      }
      // cout<<ind<<endl;
      ll first = seen[now]-1;
      // cout<<first<<endl;
      ll length = ind - first-1;
      ll k = (n-first)/length;
      // cout<<length<<" "<<k<<endl;

      ans = k* (pref[ind-1] - pref[first]) + pref[first];
      // cout<<ans<<endl;
      ll last = first + 1 + length*k;
      // cout<<last<<endl;

      while (last<=n){
        ans+=now;
        now = power(now, 2) % m;
        last++;
      }
      cout<<ans<<"\n";



}