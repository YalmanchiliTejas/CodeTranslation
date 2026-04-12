#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

int main() {
  int h,w;cin>> h>>w;
  vector<pair<int,int>> vh,vw;
  set<pair<int,int>> sth,stw;
  string field[w][h];
  for(int j=0;j<h;++j){
    string s;cin >>s;
    for(int i=0;i<w;++i){
      string sub = s.substr(i,1);
      field[i][j] = sub;
    }
  }
  for(int j=0;j<h;++j){
    for(int i=0;i<w;++i){
      if(field[i][j] == "#"){
        if(i+1<w) if(field[i+1][j] == "#"){
          vw.push_back(make_pair(i,i+1));
          stw.insert(make_pair(i,i+1));
        }
        if(j+1<h) if(field[i][j+1] == "#"){
          vh.push_back(make_pair(j,j+1));
          sth.insert(make_pair(j,j+1));
        }
      }
    }
  }
  int vec_w_size = vw.size();
  int vec_h_size = vh.size();
  int set_w_size = stw.size();
  int set_h_size = sth.size();
  if(vec_w_size != set_w_size || vec_h_size != set_h_size){
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
  }
  return 0;
}
