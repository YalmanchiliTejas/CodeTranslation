#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

// 4と9を含まない数字の組合せ
long dp[20000][2][100];
int D;
// 各桁の総和を知りたい場合は引数にsum,判定にsum==D
long rec(string &s, int k=0, bool tight=true, int sum=0){
  if(k == s.size()){
    //条件によって返す値が決まる
    return (sum == 0);
  }

  int m = s.at(k) - '0'; //k桁目の数字

  if(dp[k][tight][sum] != -1) return dp[k][tight][sum];

  int x = (tight ? m : 9);
  long res = 0;
  for(int i=0; i<=x; i++){
    //if(i == 4 || i == 9) continue;
    res += rec(s, k+1, i==x && tight, (sum+i)%D);
    res %= MOD;
  }

  return dp[k][tight][sum] = res;
}

void dpInit(long value=-1, int a = 1, int b = 1, int c = 1){
  for(int i=0; i<a; i++){
    for(int j=0; j<b; j++){
      for(int k=0; k<c; k++){
        dp[i][j][k] = value; 
      }
    }
  }
}

int main(){
  string s;
  cin >> s >> D;
  dpInit(-1,20000,2,100);
  cout << (rec(s,0,true,0) + MOD - 1) % MOD << endl;
}