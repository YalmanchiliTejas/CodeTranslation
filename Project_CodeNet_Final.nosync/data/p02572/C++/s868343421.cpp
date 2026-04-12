#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)

/*
 // 深さ優先探索
vector<bool> seen;
int dfs(const Graph &G, ll v) {
    seen[v] = true; // v を訪問済にする
    int score = 0; 

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー

        // 負荷さ優先探索中の処理



        dfs(G, next_v); // 再帰的に探索, 毎回mat渡してええの？
    }
    return score;
} */

/*
//桁数の計算
ll keta(ll num){
  ll ans= 0 ;
  ll rem;

  for (ll i = 4; i >= 0 ; i--){
    rem = pow(10,i);
    ans += (num / rem); 
    num = num % rem;
  }
  return ans;
}
*/


int main() {
  ll N;
  cin >> N;
  vector<ll> A(N+1);
  vector<ll> save(N+1);


  for (ll i=1; i<N+1; i++){
    cin >> A[i];
  }

  ll save_sum =0;
  for (ll i=N; i >1; i--){
    save_sum += A[i];
    save_sum = save_sum % 1000000007;
    save[i] = save_sum;
    //cout << "save_sum:" << save_sum << endl;
  }

  ll sum = 0;

  for(ll i=1; i< N; i++){    
    sum += (A[i] * save[i+1]) % 1000000007;
    sum = sum % 1000000007;
    //cout << "add:"<< A[i] * save[i+1] << endl;
  }
  
  cout << sum << endl;

  return 0;
}
