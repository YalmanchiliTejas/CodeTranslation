#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  vector<long long> B(n+1,0);
  long ans = 0;
  for(int i= 0;i<n;i++){
    cin >> A[i];
    B[i+1] = B[i]+A[i];
  }
 for(int i = 0;i<n;i++){
  long long sum = (B[n]-B[i+1])%M;
   ans += A[i]*sum;
   ans %=M;
 }
 cout << ans << endl;
 return 0;
}