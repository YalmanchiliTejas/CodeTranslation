#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main() {
  ll h, w;
  cin >> h >> w;
  char board[h][w];
  rep(i,h){
    rep(j,w){
      cin>>board[i][j];
    }
  }
  
  vector<int>vec;
  rep(i,h){
    rep(j,w){
      if(board[i][j]=='#'){
        vec.push_back(j);
      }
    }
  }
  
  bool can=true;
  int sum=0;
  rep(i,vec.size()-1){
    if(vec[i]+1 ==vec[i+1] || vec[i] ==vec[i+1]){
      if(vec[i] ==vec[i+1]) sum++;
    }
    else{
      can=false;
      break;
    }
  }
  if(can){
    if(sum==h-1) cout<<"Possible";
    else cout<<"Impossible";
  }
  else cout<<"Impossible";
  return 0;
}
