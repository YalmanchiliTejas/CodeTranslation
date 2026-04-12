#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,a=pow(10,9)+7;
  cin >> N;
  vector<ll> vec(N);
  ll cnt=0;
  for(int i=0;i<N;i++){
    cin >> vec[i];
    cnt+=vec[i];
    cnt%=a;
  }
  ll ans=0;
  for(int i=0;i<N;i++){
    cnt-=vec[i];
    if(cnt<0){
      cnt+=a;
    }
    ans+=cnt*vec[i];
    ans%=a;
  }
  cout << ans <<endl;
}
  