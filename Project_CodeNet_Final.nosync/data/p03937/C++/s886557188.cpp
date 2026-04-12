#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll h,w;
  cin >> h >> w;

  std::vector<vector<char>> a(h,vector<char>(w));
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      cin >> a.at(i).at(j);
    }
  }

  char data;
  ll first,mas=0;
  for(ll i=0;i<h;i++){
    first=1;
    for(ll j=0;j<w;j++){
      data=a.at(i).at(j);

      if(data=='#'){
        if(mas>j){
          cout << "Impossible" << endl;
          return 0;
        }
        else if(mas==j){
          mas=j;
          first=0;
        }
        else if(mas+1==j && first==0){
          mas=j;
        }
        else{

          if(first==0){
          cout << "Impossible" << endl;
          return 0;
          }

        }
      }

    }
  }

  cout << "Possible" << endl;
  return 0;

  }