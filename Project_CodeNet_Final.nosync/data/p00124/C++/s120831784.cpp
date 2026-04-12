#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n;
  bool notfirst = false;
  while(cin >> n && n){
    if(notfirst){
      cout << "\n";
    }
    else{
      notfirst = true;
    }
    vector<pair<int, pair<int, string> > > v(n);
    for(int i = 0; i < n; i++){
      string team;
      int w, l, d;
      cin >> team >> w >> l >> d;
      v[i] = make_pair(-(w * 3 + d), make_pair(i, team));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
      cout << v[i].second.second << "," << -v[i].first << "\n";
    }
  }
  return 0;
}