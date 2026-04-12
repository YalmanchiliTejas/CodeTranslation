#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> Team;

int main(void){  
  int n, firstDS=0;
  
  while (cin >> n){
    vector<Team> v;
    if (n==0) break;
    if (firstDS==0) firstDS= 1;
    else cout << endl;
    for (int i=0; i<n; i++){
      string nm;
      int w,l,d;
      Team t;
      cin >> nm >> w >> l >> d;
      t = make_pair(w*3+d, (char)('z'-i)+nm);
      v.push_back(t);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i=0; i<n; i++){
      cout << (v[i].second.c_str()+1) << ",";
      cout << v[i].first << endl;
    }
  }
  return 0;
}
