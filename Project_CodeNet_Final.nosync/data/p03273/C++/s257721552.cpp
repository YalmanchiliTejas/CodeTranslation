#include <iostream>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int h;cin>>h;
  int w;cin>>w;
  
  vector<string> a(h);
  
  for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
  vector<bool> tate(h);
  vector<bool> yoko(w);
  
  rep(i,h) {
    rep(j,w) {
      if (a.at(i).at(j) == '#'){
        tate.at(i) = true;
        yoko.at(j) = true;
      }
    }
  }
  
  rep(i,h){
    if(tate.at(i)){
      rep(j,w) {
        if (yoko.at(j)){
          cout << a.at(i).at(j) ;
        }
      }
      cout << endl;
    }
  }
  return 0;
}