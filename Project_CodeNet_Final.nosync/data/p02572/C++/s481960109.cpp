#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin>>N;
  vector<long long int> a(N);
  vector<long long int> b(N);
  long long int sum=0;
  long long int x = 1000000007;
  for(int i=0;i<N;i++){
    long long int y;
    cin>>y;
    a[i]=y;
    sum+=y;
    sum%=x;
    b[i]=sum;
  }
  sum=0;
  
  for(int i=N-1;i>0;i--){
    sum+= a[i]*b[i-1]%x;
    sum%=x;
  }
  
  cout<<sum<<endl;
  return 0;
}