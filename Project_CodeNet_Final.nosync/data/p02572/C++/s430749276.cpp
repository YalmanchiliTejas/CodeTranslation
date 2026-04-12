#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long a[n], b[n], ans=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(i!=0){
      b[i] = b[i-1] + a[i];
    } else {
      b[i] = a[i];
    }
    b[i] %= 1000000007;
  }
  for(int i = n-1;i>0;i--){
    ans += a[i] * b[i-1] % 1000000007;
  }
  ans %= 1000000007;
  cout << ans << endl;
}
