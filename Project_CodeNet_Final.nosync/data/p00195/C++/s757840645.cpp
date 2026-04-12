#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(void){
  int a, b;
  
  while (cin >> a >> b){
    vector<pair<int, int> > v;
    if (a==0 && b==0) break;
    v.push_back(make_pair(a+b, 0));
    for (int i=1; i<5; i++){
      cin >> a >> b;
      v.push_back(make_pair(a+b, i));
    }
    sort(v.begin(), v.end());
    cout << (char)('A'+v[4].second) << " " << v[4].first << endl;
  }
  return 0;
}
  
  

