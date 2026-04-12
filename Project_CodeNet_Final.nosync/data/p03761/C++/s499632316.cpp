#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
typedef long long ll;
const int inf = 100100100;

int main(){
  int n;
  cin >> n;

  string t = "abcdefghijklmnopqrstuvwxyz";

  vector<int> a(26,inf);
  rep(i,n){
    string u;
    cin >> u;
    vector<int> b(26,0);
    rep(j,u.size()){
      rep(k,26){
        if(u[j] == t[k]) b[k]++;
      }
    }
    rep(j,26){
      a[j] = min(a[j],b[j]);
    }
  }
  rep(i,26){
    rep(j,a[i]) cout << t[i];
  }
  cout << endl;
}

