#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

signed main(){
  int n;
  cin>>n;
  int ans=0;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin>>a[i];
  }
  int sum = a[0];
  for(int i =1; i < n; i++){
    ans = (ans + ((sum * a[i]) % MOD)) % MOD;
    sum = (sum + a[i]) % MOD; 
  }
  cout << ans <<endl;
}