#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define veci(i,n) vector<int> i((int) (n))
#define vecs(i,n) vector<string> i((int) (n))

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> data(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> data.at(i).at(j);
      //cout << data.at(i).at(j);
    }
  }
  veci(x,100);
  veci(y,100);
  int xn=0;
  int yn=0;
  
  rep(i,h){
    rep(j,w){
      if(data.at(i).at(j) == '#'){
        x.at(xn) = i;
        xn++;
        break;
      }
    }
  }
  
  rep(i,w){
    rep(j,h){
      if(data.at(j).at(i) == '#'){
        y.at(yn) = i;
        yn++;
        break;
      }
    }
  }
  int p,q;
  rep(i,xn){
    p = x.at(i);
    rep(j,yn){
      q = y.at(j);
      //cout << p << q;
      cout << data.at(p).at(q);
    }
    cout << endl;
  }
}