#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int h,w;
    cin >> h >> w;
    vector<string> v;
    rep(i,h){
      string tmp;
      cin >> tmp;
      v.emplace_back(tmp);
    }

    bool a[w+5];
    rep(i,h){
      a[i] = true;
      for(int j=0; j<w; j++){
        if(v[i][j]!='.') a[i]=false;
      }
    }

    bool b[h+5];
    rep(i,w){
      b[i]=true;
      for(int j=0; j<h; j++){
        if(v[j][i]!='.') b[i]=false;
      }
    }


    rep(i,h){
      rep(j,w){
        if(!b[j]&&!a[i]) cout << v[i][j];
      }
      if (!a[i]) cout << endl;
    }
    cout << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
