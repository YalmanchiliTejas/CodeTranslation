#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define veci(x,n) vector<int> x((int) (n))
#define vecs(x,n) vector<string> x((int) (n))
#define vecbf(x,n) vector<bool> x((int) (n), false)

int main(){
  int h,w;
  cin >> h >> w;
  vecs(data,h);
  rep(i,h) {
    cin >> data.at(i);
    //cout << data.at(i);
  }
  
  vecbf(x,h);
  vecbf(y,w);
  
  rep(i,h){
    rep(j,w){
      if(data.at(i).at(j) == '#'){
        x.at(i) = true;
        y.at(j) = true;
      }
    }
  }
  
  rep(i,h){
    if(x.at(i)){
      rep(j,w){
        if(y.at(j)){
          cout << data.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
