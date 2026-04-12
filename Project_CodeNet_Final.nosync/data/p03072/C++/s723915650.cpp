#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,h,c=0; cin>>n;
  vector<int> v(n);
  rep(i,n){
    cin>>v.at(i);
    if(i==0){h=v.at(0);c++;}
    else if(v.at(i)>=h){h=v.at(i);c++;}
  }
  cout<<c;
}
      