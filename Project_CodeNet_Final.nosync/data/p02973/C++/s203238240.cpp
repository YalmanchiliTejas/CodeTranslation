#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) {
    cin >> a.at(i);
  }
  vector<int>d;
  d.push_back(-a[0]);
  rep2(i,1,n){ 
    if(d[d.size()-1]<=-a[i]){
      d.push_back(-a[i]);
    }
    else{
      int itr = upper_bound(d.begin(), d.end(), -a[i])-d.begin();
      d[itr]=-a[i];
    }
    
  }
  cout<<d.size()<<endl;
}