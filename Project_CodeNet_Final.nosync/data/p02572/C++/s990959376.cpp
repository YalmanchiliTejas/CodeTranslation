#include <bits/stdc++.h>
using namespace std;
using LL=long long;

int main(){
 int MOD=1000000007;
  int N;
  LL ans = 0;
  LL sum=0,suma;
  
  cin >> N;
  vector<LL>vec(N);
  for(int i=0;i<N;i++){
    cin >> vec.at(i);
    sum+=vec.at(i);
  }
  
  for(int i=0;i<N-1;i++){
    sum-=vec.at(i);
    suma=sum%MOD;
    ans+=vec.at(i)*suma;
    ans=ans%MOD;
  }
  
  cout << ans <<endl;
}