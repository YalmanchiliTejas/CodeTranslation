#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
#define div 1000000007
 
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b;
  int sum = 0;
  
  rep(i,n){
    cin >> a[i];
    sum = (sum + a[i]) % div;;
    b.emplace_back(sum);
  }
  
  int ans = 0;
  rep(i,n-1){
      ans = (ans + (ll)a[i+1]*b[i]) % div;
  }
  cout << ans << endl;
  return 0;
}