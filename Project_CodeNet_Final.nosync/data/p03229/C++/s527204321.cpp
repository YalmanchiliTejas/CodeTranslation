#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long int> a(n);
  for(int i=0; i<n; i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  long long int ans=0;
  long long int ans2=0;
  if(n>=4){
  if(n%2 == 0){
    for(int i=0; i<n; i++){
      if(i+1<n/2){
        ans -= a.at(i)*2;
      }
      if(i+1 == n/2){
        ans -= a.at(i);
      }
      if(i+1 == n/2+1){
        ans += a.at(i);
      }
      if(i+1 > n/2+1){
        ans += a.at(i)*2;
      }
    }
  }else{
    for(int i=0; i<n; i++){
      if(i+1<(n-1)/2){
        ans -= a.at(i)*2;
      }
      if(i+1 == (n-1)/2){
        ans -= a.at(i);
      }
      if(i+1 == (n+1)/2){
        ans -= a.at(i);
      }
      if(i+1 > (n+1)/2){
        ans += a.at(i)*2;
      }
      
      if(i+1<(n+1)/2){
        ans2 -= a.at(i)*2;
      }
      if(i+1 == (n+1)/2){
        ans2 += a.at(i);
      }
      if(i+1 == (n+3)/2){
        ans2 += a.at(i);
      }
      if(i+1 > (n+3)/2){
        ans2 += a.at(i)*2;
      }
    }
  }
  }
  if(n == 2){
    ans = a.at(1)-a.at(0);
  }
  if(n == 3){
    ans = max(a.at(1)-a.at(0)+a.at(2)-a.at(0),a.at(2)-a.at(1)+a.at(2)-a.at(0));
  }
  cout << max(ans,ans2) << endl;
}