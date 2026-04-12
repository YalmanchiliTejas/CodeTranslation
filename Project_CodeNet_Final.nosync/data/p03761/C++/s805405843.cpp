#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> P;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz size()
#define print(X) cout << (X) << endl
const int INF = 1e+8+7;
ll n,m,l;
string s,t;
ll d[100],dp[500][500];
char field[100][100];

int main(){
  t = "";
  clr(dp,0);
  cin >> n;
  rep(i,0,n){
    cin >> s;
    rep(j,0,s.sz){
      dp[i][s[j]-'a']++;
    }
  }
  rep(i,0,26){
    bool f = false;
    m = INF;
    rep(j,0,n){
      if(dp[j][i] == 0){
        f = true;
        break;
      }
      m = min(m,dp[j][i]);
    }
    if(f)continue;
    rep(j,0,m){
      t += 'a'+i;
    }
  }
  print(t);
  return 0;
}