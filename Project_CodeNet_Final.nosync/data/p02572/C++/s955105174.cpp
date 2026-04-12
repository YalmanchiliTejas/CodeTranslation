#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> vec(N);
  ll sum=0;
  for(int i=0;i<N;i++){
    cin >> vec[i];
    sum+=vec[i];
  }
  ll a=pow(10,9)+7;
  ll ans=0;
  for(int i=0;i<N-1;i++){
    sum-=vec[i];
    ll b=sum%a;
    ans=(ans+(b*vec[i]))%a;
   
  }
  cout << ans <<endl;
}
  
    