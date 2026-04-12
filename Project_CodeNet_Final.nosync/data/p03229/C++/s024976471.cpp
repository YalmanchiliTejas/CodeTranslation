#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> A(N),v1(N,2),v2(N,2);
  v1.front()=1;
  v1.back()=1;
  v2.front()=1;
  v2.back()=1;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    if(i%2==0){
      v1.at(i)*=-1;
    }else{
      v2.at(i)*=-1;
    }
  }
  sort(A.begin(),A.end());
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  int64_t sum1=0;
  int64_t sum2=0;
  for(int i=0;i<N;i++){
    sum1+=A.at(i)*v1.at(i);
    sum2+=A.at(i)*v2.at(i);
  }
  cout << max(sum1,sum2) << endl;
  return 0;
}
