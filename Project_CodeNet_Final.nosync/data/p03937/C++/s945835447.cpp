#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAXs
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

int main(){
  int h,w; cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  bool ans = true;
  rep(i,h) rep(j,w) cin >> a.at(i).at(j);

  int max;
  for(int i = w-1;i>=0;i--){
    if(a.at(0).at(i)=='#'){
      max = i;
      break;
    }
  }
  for(int i=1;i<h;i++){
    int min;
    rep(j,w){
      if(a.at(i).at(j)=='#'){
        min = j;
        break;
      }
    }

    if(min<max){
      ans = false;
      break;
    }

    for(int j=w-1;j>=0;j--){
      if(a.at(i).at(j)=='#'){
        max = j;
        break;
      }
    }
  }

  if(ans) puts("Possible");
  else puts("Impossible");
}
