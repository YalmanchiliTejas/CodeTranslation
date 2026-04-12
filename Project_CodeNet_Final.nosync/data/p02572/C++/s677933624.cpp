#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin >> n;
  long long int mod=1000000007;
  vector<long long int> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  long long int x=0,ans=0;
  for(int j=1;j<n;j++){
    x+=a.at(j-1);
    x%=mod;
    ans+=a.at(j)*x;
    ans%=mod;
  }
  cout << ans << endl;
}