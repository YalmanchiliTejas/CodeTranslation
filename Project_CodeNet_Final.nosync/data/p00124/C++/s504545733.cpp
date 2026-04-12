#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int n, cnt = 0;
  while(cin >> n, n) {
    if(cnt++ != 0) cout << endl;
    vector<pair<string, int>> p(n);
    for(int i = 0; i < n; i++) {
      string s;
      int w, l, d;
      cin >> s >> w >> l >> d;
      p[i].first = s, p[i].second = w*3 + d;
    }

    for(int i = 0; i < n; i++) {
      int max = 0;
      for(int j = 0; j < n; j++) {
	if(p[j].second > max) max = p[j].second;
      }

      for(int j = 0; j < n; j++) {
	if(p[j].second == max) {
	  cout << p[j].first << ',' << p[j].second << endl;
	  p[j].second = -1;
	}
      }
    }
  }
}