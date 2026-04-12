#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int ans = 0, h, w;
  cin >> h >> w;
  int a[h][w], bad_h[h] = {0}, bad_w[w] = {0};
  REP(i,0,h){
    int cnt = 0;
    REP(j,0,w){
      char inter;
      cin >> inter;
      if(inter=='.'){a[i][j]=0; cnt++;}
      else a[i][j]=1;
    }
    if(cnt==w)bad_h[i] = 1;
    else bad_h[i] = 0;
  }
  REP(j,0,w){
    int cnt = 0;
    REP(i,0,h){
      if(a[i][j]==0)cnt++;
    }
    if(cnt==h)bad_w[j] = 1;
    else bad_w[j] = 0;
  }

  REP(i,0,h){
    if(bad_h[i]==1)continue;
    REP(j,0,w){
      if(bad_w[j]==1)continue;
      if(a[i][j]==1)cout << "#";
      else cout << ".";
    }
    cout << endl;
  }

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}