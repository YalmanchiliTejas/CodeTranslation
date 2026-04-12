#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<long long> a(n);
  long long sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  vector<long long> ans;
  for(int i=0;i<n-1;i++){
    sum+=(long long)1e9+7-a[i];
    sum%=(long long)1e9+7;
    ans.push_back(a[i]*sum);
  }
  long long res=0;
  for(auto x:ans){
    x%=(long long)1e9+7;
    res+=x;
  }
  res%=(long long)1e9+7;
  cout<<res<<endl;
  return 0;
}
