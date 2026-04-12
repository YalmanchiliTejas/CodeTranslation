#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;

int main()
{
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  rep(i,h){
    cin>>s[i];
  }
  vector<bool>col(h, false);
  vector<bool>row(w, false);
  rep(i,h){
    rep(j,w){
      if(s[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  rep(i, h){
    if(row[i]){
      rep(j,w){
        if(col[j]){
          cout << s[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}