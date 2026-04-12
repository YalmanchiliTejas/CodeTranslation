#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int64_t>a(n);
    int64_t ans=0,sum=0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sum+=a.at(i);
  }
  for(int i=0;i<n-1;i++){
    sum-=a.at(i);
    ans=(ans+sum%1000000007*a.at(i))%1000000007;
  }
  cout << ans << endl;
  return 0;
}