#include <bits/stdc++.h>
const int mod=1e9+7;
using LL=long long;
using namespace std;
namespace ndifix{

}//end of namespace ndifix

int main(){
  int n;
  cin>>n;
  vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];
  vector<int> c;
  c.push_back(a[0]);
  for(int i=1;i<n;i++){
    int locate=distance(c.begin(),lower_bound(c.begin(),c.end(),a[i]));
    if(locate==0)c.insert(c.begin(),a[i]);
    else c[locate-1]=a[i];
  }
  cout<<c.size()<<endl;
  return 0;
}
