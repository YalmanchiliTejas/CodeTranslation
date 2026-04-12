#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  cin>>q;
  vector<int>::iterator it;
  for(int i=0;i<q;i++){
    int a;
    cin>>a;
    it=lower_bound(v.begin(),v.end(),a);
    cout<<(it-v.begin())<<endl;
  }
  return 0;
}

