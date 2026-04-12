#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,mod=1e9+7;
  cin >> N;
  vector<int> A(N);
  long long sum=0,res=0;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    sum+=A.at(i);
  }
  for(int i=0;i<N;i++){
    sum-=A.at(i);
    long long B=sum%mod;
    long long C=B*A.at(i)%mod;
    res=(res+C)%mod;
  }
  cout << res << endl;
}
    