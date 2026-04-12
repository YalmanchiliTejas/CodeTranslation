#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>


#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long
//#define lint long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
char s[200000];
int ans[4][200000];
signed main(){
  int n;
  cin >> n;
  REP(i,n) cin >> s[i];
  ans[0][0] = 1;
  ans[0][1] = 1;
  ans[1][0] = 1;
  ans[1][1] = -1;
  ans[2][0] = -1;
  ans[2][1] = 1;
  ans[3][0] = -1;
  ans[3][1] = -1;
  REP(i,4){
    REP(j,n-2){
      if(s[j+1]=='o'){
        ans[i][j+2] = ans[i][j] * ans[i][j+1];
      }
      else ans[i][j+2] = ans[i][j] * ans[i][j+1] * -1;
    }
    int f = 0;
    if(s[n-1]=='o'){
      if(ans[i][n-1] !=  ans[i][n-2]*ans[i][0]) f = 1;
    }
    else{
      if(ans[i][n-1] ==  ans[i][n-2]*ans[i][0]) f = 1;
    }
    if(s[0]=='o'){
      if(ans[i][0] !=  ans[i][n-1]*ans[i][1]) f = 1;
    }
    else{
      if(ans[i][0] ==  ans[i][n-1]*ans[i][1]) f = 1;

    }
    if(f==0){
      REP(j,n){
        if(ans[i][j]==1) cout << 'S';
        else cout << 'W';
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
