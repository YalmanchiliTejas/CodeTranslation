#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;
ll MOD=1000000007;

int main(){
  int h,w; cin>>h>>w;
  vector<string>S(h);
  rep(i,h) cin>>S[i];
  vector<bool> R(h,false), C(w,false);
  rep(i,h) rep(j,w){
    if (S[i][j]=='#') R[i]=true, C[j]=true;
  }
  rep(i,h){
    if (R[i]){
      rep(j,w){
        if (C[j]) cout << S[i][j];
      }
      cout << endl;
    }
  }
}