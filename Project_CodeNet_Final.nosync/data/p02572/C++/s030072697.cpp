#include <bits/stdc++.h>
#include <map>
 #define rep(i,n) for(int i=0;i<(n);i++)
 using namespace std;
  int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      int mod = 1000000007;
      long long sum = 0;
      rep(i,n){
          cin >> a[i];
          sum += a[i];
          sum %= mod;
      }
      long long ans =0;
      rep(i,n){
          sum -= a[i];
          if(sum<0)sum += mod;

          ans += a[i]*sum;
          ans %= mod;
      }
      cout << ans << endl;
      return 0;
  }