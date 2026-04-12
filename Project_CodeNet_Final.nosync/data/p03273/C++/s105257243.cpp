#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int h,w ; 
  cin >> h >> w ; 
  vector<vector<char>> D(h ,vector<char> (w));
  rep(i,h){
    rep(j,w){
      cin >> D.at(i).at(j) ;
    }
  }
  
  vector<int> row , column;
  
  rep(i,h){
    int  cnt = 0 ;
    rep(j,w){
      if(D.at(i).at(j) == '.') cnt ++ ;
    }
    if(cnt != w) row.push_back(i) ;
  }
  
  rep(i,w){
    int  cnt = 0 ;
    rep(j,h){
      if(D.at(j).at(i) == '.')  cnt ++  ;
    }
    if(cnt != h) column.push_back(i) ;
  }
  
  
  rep(i,row.size()){
    rep(j,column.size()){
      cout << D.at(row.at(i)).at(column.at(j)) ;
    }
    cout <<endl;
  }
  
}
