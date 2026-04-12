#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){

  int n,s,ans;
  vector<int> list;
  while(1){
    cin >>n;
    list.resize(n);
    if(n==0)return 0;
    rep(i,n)
      cin>>list[i];
    sort(list.begin(),list.end());
    ans=0;
    for(int i=1;i<n-1;i++)
      ans+=list[i];
    ans/=n-2;
    cout<<ans<<endl;
  }
  return 0;
}