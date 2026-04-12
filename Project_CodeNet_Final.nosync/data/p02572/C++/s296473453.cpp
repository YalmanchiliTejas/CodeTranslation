#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int n;
 cin >> n;
 vector<long long> a(n);
 rep(i,n) {
  cin >> a.at(i);
  }
  long long ans = 0;
  
  long long sum =0;
   rep(i,n) {
   ans = (ans+a.at(i)*sum)%1000000007;
   sum=(sum+a.at(i))%1000000007;    
   
   }

    
    cout << ans;
 }
