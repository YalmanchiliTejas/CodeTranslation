#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,m=0,a[100000],r=0;
  vector <int> li;
  cin>>n;
  for(int i=0;i<n;m=max(m,a[i]),i++) cin>>a[i];
  for(int i=1;i<=m;i++) if(__gcd(i,m)==i) li.push_back(i);
  for(int i=0;i<n;i++) r+=*lower_bound(li.begin(),li.end(),a[i])-a[i];
  cout<<r<<endl;
  return 0;
}