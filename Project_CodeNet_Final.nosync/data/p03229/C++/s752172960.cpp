#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  sort(an.begin(),an.end());
  ll ans = 0;
  if(n==2){
    cout << an[1]-an[0] << endl;
    return 0;
  }
  for(int i=0; i<n/2; ++i){
    if(i == 0) ans += an[n-1]+an[n-2] - an[0]*2;
    else ans += an[n-i]+an[n-i-2] - an[i]*2;
  }
  if(n%2==1){
    ans -= an[n/2] - an[n/2-1];
    ans += max(an[n/2] - an[n/2-1], an[n/2+1] - an[n/2]);
  }
  cout << ans << endl;
}