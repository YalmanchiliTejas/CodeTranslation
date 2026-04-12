#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a;
  cin >> n;
  vector<int> b(n),c;
  for(int i=0;i<n;i++){
    cin >> b.at(i);
  }
  reverse(b.begin(),b.end());
  c.push_back(b.at(0));
  for(int i=1;i<n;i++){
    auto iter = upper_bound(c.begin(),c.end(),b.at(i)+0.5);
    if(iter == c.end()){
      //cout << b.at(i) << " saigoni" << endl;
      c.insert(iter,b.at(i));
    }
    else if(iter != c.end()){
      //cout << b.at(i) << "kesimasu" << endl;
      c.erase(iter);
      c.insert(iter,b.at(i));
    }
  }
  cout << c.size() << endl;
}