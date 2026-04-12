#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H,W;
  cin >> H >> W;
  char S[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> S[i][j];
    }
  }
  bool flg=true;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(S[i][j] == '#') flg = false;
    }
    if(flg){
      for(int j=0;j<W;j++){
        S[i][j] = ' ';
      }
    }
    else flg = true;
  }
  flg=true;
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(S[i][j] == '#') flg = false;
    }
    if(flg){
      for(int i=0;i<H;i++){
        S[i][j] = ' ';
      }
    }
    else flg = true;
  }

  for(int i=0;i<H;i++){
    flg = true;
    for(int j=0;j<W;j++){
      if(S[i][j] == '.' || S[i][j] == '#'){
        cout << S[i][j];
        flg = false;
      }
    }
    if(!flg) cout << endl;
  }
  
  
}