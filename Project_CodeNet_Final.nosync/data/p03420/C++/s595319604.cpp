#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,k;
  cin >> n >> k;
  long long ans=0;
  for(int i=k+1;i<=n;i++){
    ans+=n/i*(i-k)+max((long long)0,n%i-k+(k!=0));
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}