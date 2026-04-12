#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans=0;
  cin >> n;
  vector<long long> da(n);
  for(int i=0;i<n;i++)
    cin >> da[i];
  sort(da.begin(),da.end());
  if(n%2==0){
    for(int i=0;i<n/2;i++)
      ans-=da[i]*2;
    for(int i=n/2;i<n;i++)
      ans+=da[i]*2;
    ans-=da[n/2]-da[n/2-1];
  }
  else{
    for(int i=0;i<n/2;i++)
      ans-=da[i]*2;
    for(int i=n/2+1;i<n;i++)
      ans+=da[i]*2;
    ans-=min(da[n/2]-da[n/2-1],da[n/2+1]-da[n/2]);
  }
  cout << ans << endl;
}