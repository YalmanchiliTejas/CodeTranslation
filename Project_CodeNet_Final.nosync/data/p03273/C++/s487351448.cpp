#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define out(x) cout<<x<<endl
#define put(x) out(x)
#define in(x) cin>>x
#define maxx(a,b,c) max(a,max(b,c))
#define minn(a,b,c) min(a,min(b,c))
using ll = unsigned long long;
using vl = vector<ll>;
using vs = vector<string>;
const double pi = 3.14159265358979;
const ll mod = 1000000007;
int main() {
  int H,W;
  in(H>>W);
 vector<vector<char>> P(H,vector<char>(W));
  rep(i,H){
   rep(j,W) in(P[i][j]);
  }
  vector<bool> cuth(H,true),cutw(W,true);
  rep(i,H){
   bool f = true;
    rep(j,W) if(P[i][j]=='#') f = false;
    if(f) cuth[i]=false;
  }
  rep(i,W){
   bool g = true;
    rep(j,H) if(P[j][i]=='#') g = false;
    if(g) cutw[i]=false;
  }
 rep(i,H){
  rep(j,W){
   if(cuth[i]==true&&cutw[j]==true) cout <<P[i][j];
    if(cuth[i]==true&&j==W-1) cout<<endl;
  }
 }
}
