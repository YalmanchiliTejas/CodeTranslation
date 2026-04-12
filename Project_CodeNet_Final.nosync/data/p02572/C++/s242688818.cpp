#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  long long M=1000000007;
  vector<int> A(N);
  long long sum=0;
  long long res=0;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    sum+=A.at(i);
  }
  for(int i=0;i<N;i++){
    sum-=A.at(i);
    long long B=sum%M;
    long long C=(A.at(i)*B)%M;
    res=(res+C)%M;
  }
  cout << res << endl;
}
    
    