#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >>a.at(i);
  }
  sort(a.begin(),a.end());
  long long int ans =0;
  if(n%2 == 0){
    for(int i=0;i<n/2;i++){
      ans += a.at(i+n/2);
    }
    for(int i=0;i<n/2;i++){
      ans -= a.at(i);
    }
    ans *= 2;
    ans += a.at(n/2-1)-a.at(n/2);
    cout << ans <<endl;
    return 0;
  }
  if(n%2 == 1){
    long long int u,v;
    for(int i=0;i<n/2;i++){
      u += a.at(n-1-i);
    }
    for(int i=0;i<n/2;i++){
      u -= a.at(i);
    }
    u *= 2;
    u += a.at(n/2-1)-a.at(n/2);
    for(int i=0;i<n/2;i++){
      v += a.at(i);
    }
    for(int i=0;i<n/2;i++){
      v -= a.at(n-1-i);
    }
    v *= 2;
    v += a.at(n/2+1)-a.at(n/2);
    v = abs(v);
    ans = max(u,v);
    cout << ans <<endl;
    return 0;
  }
}