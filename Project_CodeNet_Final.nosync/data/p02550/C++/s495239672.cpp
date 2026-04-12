#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
全部計算はちょいむり
ループするはず？


*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, X, M;
  cin >> N >> X >> M;
  vector<int> seen(100010, 0);
  ll now = X, ans = 0, count = 0;
  rep(i, N){
    if (seen[now] == 2)
      break;
    seen[now]++;
    count++;
    ans += now;
    now *= now;
    now %= M;
//cout << now << endl;
  }
  if (count == N){
    cout << ans << endl;
    return 0;
  }
  ll loop = 0, point = 0;
  rep(i, 100001){
    if (seen[i] == 2){
      loop++;
      point += i;
    }
  }
  N -= count;
  ll loop_count = N / loop;
  ans += loop_count * point;
  N %= loop;
  while (N > 0){
    ans += now;
    now *= now;
    now %= M;
    N--;
  }
  cout << ans << endl;
}
