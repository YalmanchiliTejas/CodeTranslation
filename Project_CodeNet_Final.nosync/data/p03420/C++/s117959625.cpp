#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,k,ans=0;
  cin >> n >> k;
  if(k==0){
    cout << n*n << endl;
    return 0;
  }
  for(int i=k+1;i<=n;i++){
    ans+=(i-k)*(n/i);
    ans+=max(n%i-k+1,0ll);
  }
  cout << ans << endl;
  return 0;
}
