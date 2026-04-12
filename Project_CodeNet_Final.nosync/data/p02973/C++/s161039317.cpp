#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto&& x:a)cin>>x;
  vector<int> b;
  for(auto&& x:a){
    auto it = upper_bound(b.begin(), b.end(), x, greater<int>());
    if(it == b.end()){
      b.emplace_back(x);
    }
    else{
      *it = x;
    }
  }
  cout << b.size() << endl;
}