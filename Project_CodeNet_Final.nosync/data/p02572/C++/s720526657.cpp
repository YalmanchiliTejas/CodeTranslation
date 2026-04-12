#include<bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> p(N);
  int64_t sum=0,x=0;
  
  for(int64_t i=0;i<N;i++){
    cin >> p.at(i);
  }
  
  for(int64_t i=N-1;i>0;i--){
    x+=p.at(i) % MOD;
    x%= MOD;
    sum += x * p.at(i-1) % MOD;
  }
  
  sum %= MOD;
  cout << sum << endl;
}