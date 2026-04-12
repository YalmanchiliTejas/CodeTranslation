#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<string>
#include<utility>
#include<vector>

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define per(i, a, n)  for(int i=n-1; i>=a; i--)
#define all(x)  (x).begin(), (x).end()
#define MAX 10000
using namespace std;
typedef long long int ll;

int main(){
  int h, w; cin >> h >> w;
  vector<string> map(100);
  rep(i, 0, h) cin >> map[i];

  rep(i, 0, h){
    bool check = true;
    rep(j, 0, w){
      if(map[i][j] != '.'){
        check = false;
        break;
      }
    }
    if(check){
      map.erase(map.begin()+i);
      i--;
      h--;
    }
  }

  rep(i, 0, w){
    bool check = true;
    rep(j, 0, h){
      if(map[j][i] != '.'){
        check = false;
        break;
      }
    }
    if(check){
      rep(j, 0, h){
        map[j].erase(map[j].begin()+i);
      }
      i--;
      w--;
    }
  }
  rep(i, 0, h)  cout << map[i] << endl;
  return 0;
}