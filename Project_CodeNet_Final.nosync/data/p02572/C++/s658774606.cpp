#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  signed long long A[200000]={};
  
  signed long long Ans = 0;
  signed long long kakekioku = 0;
  signed long long Anstmp = 0;
  
  for (int i=1;i<=N;i++) {
    cin >> A[i];
  }
  
  for (int i=N-1;i>=1;i--) {
    kakekioku+=A[i+1];
    Ans+=(A[i]%1000000007)*(kakekioku%1000000007);
    Ans%=1000000007;
  }
  cout << (Ans%1000000007) <<endl;
  
}