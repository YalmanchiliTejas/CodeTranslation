#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int main(void){
  int n, a, b, c;
  string s;
  vector<pair<int, pair<int, string> > > v;

  bool flag = false;
  while(cin >> n, n){
    v.clear();
    if(flag)
      cout << endl;
    else
      flag = true;

    for(int i=0; i<n; i++){
      cin >> s >> a >> b >> c;
      v.push_back(make_pair((a * 3) + c, make_pair(n - i, s)));
    }
    sort(v.begin(), v.end(), greater<pair<int, pair<int, string> > >());

    for(int i=0; i<n; i++){
      cout << v[i].second.second << "," << v[i].first << endl;
    }
  }

  return 0;
}