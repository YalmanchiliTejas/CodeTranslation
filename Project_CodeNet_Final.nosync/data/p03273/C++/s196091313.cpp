#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define vvbool vector<vector<bool>>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;
signed main(){
  int h,w;
  cin >> h >> w;
  vstring a(h);
  vvbool judge(h,vbool(w,true));
  rep(i,h) cin >> a[i];
  vbool judgeh(h,true);
  rep(i,h){
    int white = 0;
    rep(j,w){
      if(a[i][j] == '.') white++;
    }
    if(white == w){
      judgeh[i] = false;
      rep(j,w){
        judge[i][j] = false;
      }
    }
  }
  rep(i,w){
    int white = 0;
    rep(j,h){
      if(a[j][i] == '.') white++;
    }
    if(white == h){
      rep(j,h){
        judge[j][i] = false;
      }
    }
  }
  rep(i,h){
    rep(j,w){
      if(judge[i][j]) cout << a[i][j];
    }
    if(judgeh[i]) cout << endl;
  }
}