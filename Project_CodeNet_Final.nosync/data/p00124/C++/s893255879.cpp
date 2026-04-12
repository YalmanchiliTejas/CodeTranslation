#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n, W, L, E;
  bool flag = false;
  string T;
  // vector<int> vc;
  //map<int,vector<string> > res;  
  
  while(cin >> n, n) {
    vector<int> vc;
    map<int,vector<string> > res;
    if(flag) cout << endl;
    else flag = true;
    
    for(int i = 0 ; i < n ; i++) {
      cin >> T >> W >> L >> E;
      int P = -(W*3 + E);
      if(count(vc.begin(), vc.end(), P) == 0) {
	vc.push_back(P);
      }
      res[P].push_back(T);
    }
    sort(vc.begin() , vc.end());
    for(int i = 0 ; i < vc.size() ; i++)
      for(int j = 0 ; j < res[vc[i]].size() ; j++)
	cout << res[vc[i]][j] << ',' << -vc[i] << endl;
  }
  return 0;
}