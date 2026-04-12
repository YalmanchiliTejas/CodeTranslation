# include <bits/stdc++.h>
# define INF 1e9
using namespace std;

int main(){

  int H, W;
  cin >> H >> W;

  vector<string> a;
  for(int i=0; i<H; i++){
    string s;
    cin >> s;
    if(s.find('#') != string::npos){
      a.push_back(s);
    }
  }

  set<int> todelete;
  for(int j=0; j < W; j++){
    int count = 0;
    for(int i=0; i < a.size(); i++){
      if(a[i][j] == '.') count++;
    }
    if(count == a.size()) todelete.insert(j);
  }

  // for(auto j: todelete){
  //   cout << j << endl;
  // }

  vector<string> ans;
  for(int i=0; i < a.size(); i++){
    string t = "";
    for(int j=0; j< W; j++){
      if(todelete.find(j) == todelete.end()){
        t += a[i][j];
      }
    }
    cout << t << endl;
  }

}