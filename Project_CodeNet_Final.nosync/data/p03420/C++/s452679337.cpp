#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main() {
  ll N,K;
  cin>>N>>K;
  ll tmp(0);
  for(int b(1);b<=N;b++){
    //cout << tmp << endl;
    if(b <= K){
      tmp += N;
    }else{
      tmp += max(((N/b+1)*K)-1,0ll);
      tmp -= max(N/b*b+K - N - 1,0ll);
    }
  }
  //cout << tmp << endl;
  cout << N*N - tmp << endl;
  return 0;
}