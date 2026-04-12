//競技プログラミング用のテンプレート
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <stack>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repr(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;
using ll = long long int;
using p = pair<int, int>;
using pl = pair<ll, ll>;
using v = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vl = vector<ll>;

int main()
{
  string ns;
  int k;
  cin >> ns >> k;
  int d = ns.size(); 
  vector<vl> dp0(d, vector<ll>(k + 1, 0)); //ピッタリ
  vector<vl> dp1(d, vector<ll>(k + 1, 0)); //未満
  //0桁目
  dp0[0][1] = 1;
  dp1[0][1] = ns[0] - '0' - 1;
  for(int i = 0; i < d - 1; i++)
  { 
    //exact -> exact
    for(int j = 1; j < k + 1; j++)
    {
      if(ns[i + 1] == '0') dp0[i + 1][j] = dp0[i][j];
      if(ns[i + 1] != '0') dp0[i + 1][j] = dp0[i][j - 1];
    }
    //exact -> small
    for(int j = 1; j < k + 1; j++)
    {
      if(dp0[i][j] == 1)
      {
        //i桁目まででj個1以外の数がある
        if(j < k && ns[i + 1] != '0') dp1[i + 1][j + 1] =  dp0[i][j] * (ns[i + 1] - '0' - 1);
        if(ns[i + 1] != '0') dp1[i + 1][j] = dp0[i][j];
      }
    }
    //small -> small
    dp1[i][0] = 1;
    for(int j = 1; j < k + 1; j++)
    {
      dp1[i + 1][j] += dp1[i][j - 1] * 9 + dp1[i][j];
    }
  }  
  cout << dp0[d - 1][k] + dp1[d - 1][k] << endl;
}
