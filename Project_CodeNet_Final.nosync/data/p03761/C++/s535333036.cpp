#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793

int main(){
  int N; cin >> N; string S[N];
  rep(i, N){
    cin >> S[i];
  }
  int ans[26];
  rep(i, 26){
    ans[i] = inf;
  }
  rep(i, N){
    int cnt[26] = {0};
    rep(j, S[i].size()){
      cnt[S[i][j] - 'a']++;
    }
    rep(j, 26){
      ans[j] = min(cnt[j], ans[j]);
    }
  }
  rep(i, 26){
    rep(j, ans[i]){
      cout << (char) (i + 'a');
    }
  }
  cout << endl;
}