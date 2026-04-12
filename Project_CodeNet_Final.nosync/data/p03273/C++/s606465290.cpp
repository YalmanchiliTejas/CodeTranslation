#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
typedef long long ll;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> tab(h);
  rep(i,h) cin >> tab[i];
  vector<vector<bool>> skip(h,vector<bool>(w,0));
  rep(i,h){
    rep(j,w){
      if(tab[i][j] == '#'){
        skip[i][j] = 1;
        continue;
      }
      bool check1 = 0;
      bool check2 = 0;
      rep(m,w) check1 |= tab[i][m] == '#';
      rep(m,h) check2 |= tab[m][j] == '#';
      if(check1 && check2) skip[i][j] = 1;
    }
  } 
  rep(i,h){
    rep(j,w){
      if(!skip[i][j]) continue;
      cout << tab[i][j];
    }
    cout << endl;
  }
}