#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;
ll MOD=1000000007;

int main(){
  int h,w; cin>>h>>w;
  char A[h][w];
  rep(i,h) rep(j,w) cin>>A[i][j];
  vector<bool>R(h,false), C(w,false);
  rep(i,h){
    rep(j,w){
      if (A[i][j]=='#') R[i]=true;
    }
  }
  rep(i,w){
    rep(j,h){
      if (A[j][i]=='#') C[i]=true;
    }
  }

  rep(i,h){
    if (R[i]){
      rep(j,w){
        if (C[j]) cout << A[i][j];
      }
      cout << endl;
    }
  }
}