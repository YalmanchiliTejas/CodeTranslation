#include<bits/stdc++.h>
using namespace std;
int main(){
  int h, w;
  cin >> h >> w;
  vector<string> t(h);
  for(int i = 0; i < h; ++i) cin >> t[i];
  int all = 0;
  for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) if(t[i][j] == '#') all++;
  cout <<  (h + w - 1 == all ? "Possible" : "Impossible") << endl;
}