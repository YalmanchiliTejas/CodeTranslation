#include<iostream>
using namespace std;
#define ll long long
int main(){
  ll N,i;
  cin >> N;
  ll mx=0;
  ll h[N];
  for(i=0;i<N;i++){
    cin >> h[i];
  }
  ll ans=0;
  for(i=0;i<N;i++){
    if(mx<=h[i]){
      mx=h[i];
      ans++;
    }
  }
  cout << ans;
  return 0;
}