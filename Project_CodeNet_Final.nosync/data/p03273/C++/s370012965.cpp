#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  vector<int> a, b;
  for(int i = 0; i < h; i++){
  for(int j = 0; j < w; j ++){
  	cin >> s[i][j];
  }
  }
  
  for(int i = 0; i < h; i++){
    int sum = 0;
  for(int j = 0; j < w; j++){
  	if(s[i][j]=='.') sum++;
  }
    if(sum==w) a.push_back(i);
  }
  for(int i = 0; i < w; i++){
    int sum = 0;
  for(int j = 0; j < h; j++){
  	if(s[j][i]=='.') sum++;
  }
  	if(sum==h) b.push_back(i);
  }
  //a.push_back(-1); b.push_back(-1);
  int x=0, y=0;
  for(int i = 0; i < h; i++){
    bool fi = true;
    for(auto k: a) if(k==i) fi = false;
  for(int j = 0; j < w; j++){
    bool fj = true;
    for(auto l: b) if(l==j) fj = false;
    if(fi&&fj) cout << s[i][j];
  }
  if(fi) cout << endl;
  }
}