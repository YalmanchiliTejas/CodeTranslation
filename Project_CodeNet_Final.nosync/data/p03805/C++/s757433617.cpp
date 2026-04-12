#include <bits/stdc++.h>
// atoi : atoi(変数名.c_str())
// find(): int i = 変数名.find(“文字列”) 何番目にあるかを得る
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)

int ans = 0;

void search(vvi &G,vb seen,int v,int unreach){
  if(unreach == 0){
    ans++;
    return;
  }
  seen.at(v) = true;
  rep(i,G.at(v).size()){
    int nv = G.at(v).at(i);
    if(seen.at(nv)) continue;
    search(G,seen,nv,unreach-1);
  }
  return;
}

int main(){
  int n,m;
  cin >> n >> m;
  vvi G(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  vector<bool> seen(n,false);
  search(G,seen,0,n-1);
  cout << ans << endl;
}
