#include <bits/stdc++.h>
using namespace std;

long long solve (int n,long long x){
  if (x==1&&n==0){
    return 1;
  }
  else if (x==1&&n!=0){
    return 0;
  }
  else if (x<pow(2,n+1)-1){
    return solve(n-1,x-1);
  }
  else if (x==pow(2,n+1)-1){
    return pow(2,n);
  }
  else if (x<pow(2,n+2)-3){
    return pow(2,n)+solve(n-1,x-pow(2,n+1)+1);
  }
  else {
    return pow(2,n+1)-1;
  }
}
 
int main() {
  long long N,X;
  cin >> N >> X;
  long long ans=solve(N,X);
  cout << ans << endl;
}