#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> vec(n);
  rep(i,n)cin>>vec[i];
  int cnt=0,a=0;
  rep(i,n){
    if(a<=vec[i]){
      a=vec[i];
      cnt++;
    }
  }
  cout<<cnt<<endl;
}