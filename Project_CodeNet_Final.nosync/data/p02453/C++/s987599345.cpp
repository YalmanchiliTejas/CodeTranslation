#include<bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,vector<T> const& v){for(auto itr=v.begin();itr!=v.end();++itr){if(itr!=v.begin())os<<' ';os<<*itr;}return os;}

signed main(){

  int n;
  cin>>n;
  vector<int> a(n);
  for(auto& ai:a)cin>>ai;

  int q;
  cin>>q;
  while(q--){
    int k;
    cin>>k;
    cout<< lower_bound(a.begin(),a.end(),k)-a.begin() <<endl;
  }

}
