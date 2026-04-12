#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int64_t> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  int64_t sum=0;
  int64_t ksum=0;
  for(int i=1;i<N;i++){
    ksum+=vec.at(i);
    ksum=ksum%1000000007;
  }
  
  for(int i=0;i<N-1;i++){
    sum+=(vec.at(i)*ksum)%1000000007;
    sum=sum%1000000007;
    ksum-=vec.at(i+1);
    if (ksum < 0) ksum += 1000000007;
  }
  cout<<sum<<endl;  
  
}