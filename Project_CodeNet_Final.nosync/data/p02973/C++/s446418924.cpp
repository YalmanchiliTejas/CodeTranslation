#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[n-1-i];
  }
  vector<int> dp(n,2e9);
  for(int i=0;i<n;i++){
    int t=distance(dp.begin(),upper_bound(dp.begin(),dp.end(),a[i]));
    dp[t]=a[i];
  }
  cout << distance(dp.begin(),lower_bound(dp.begin(),dp.end(),2e9)) << endl;
}