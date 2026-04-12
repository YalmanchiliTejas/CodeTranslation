#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 10000000000000000;
int main(){
  int N, M;
  cin >> N >> M;
  int S, T;
  cin >> S >> T;
  S--;
  T--;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < M; i++){
    int U, V, D;
    cin >> U >> V >> D;
    U--;
    V--;
    E[U].push_back(make_pair(D, V));
    E[V].push_back(make_pair(D, U));
  }
  vector<long long> d1(N, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
  pq1.push(make_pair(0, S));
  vector<int> s1;
  while (!pq1.empty()){
    long long d = pq1.top().first;
    int v = pq1.top().second;
    pq1.pop();
    if (d1[v] == INF){
      d1[v] = d;
      s1.push_back(v);
      for (auto edge : E[v]){
        int w = edge.second;
        if (d1[w] == INF){
          pq1.push(make_pair(d + edge.first, w));
        }
      }
    }
  }
  vector<long long> dp1(N, 0);
  dp1[S] = 1;
  for (int i = 1; i < N; i++){
    int v = s1[i];
    for (auto edge : E[v]){
      int d = edge.first;
      int w = edge.second;
      if (d1[v] == d1[w] + d){
        dp1[v] += dp1[w];
        dp1[v] %= MOD;
      }
    }
  }
  vector<long long> d2(N, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq2;
  pq2.push(make_pair(0, T));
  vector<int> s2;
  while (!pq2.empty()){
    long long d = pq2.top().first;
    int v = pq2.top().second;
    pq2.pop();
    if (d2[v] == INF){
      d2[v] = d;
      s2.push_back(v);
      for (auto edge : E[v]){
        int w = edge.second;
        if (d2[w] == INF){
          pq2.push(make_pair(d + edge.first, w));
        }
      }
    }
  }
  vector<long long> dp2(N, 0);
  dp2[T] = 1;
  for (int i = 1; i < N; i++){
    int v = s2[i];
    for (auto edge : E[v]){
      int d = edge.first;
      int w = edge.second;
      if (d2[v] == d2[w] + d){
        dp2[v] += dp2[w];
        dp2[v] %= MOD;
      }
    }
  }
  long long ans = dp1[T] * dp2[S] % MOD;
  for (int i = 0; i < N; i++){
    if (d1[i] == d2[i]){
      long long tmp = dp1[i] * dp2[i] % MOD;
      long long sub = tmp * tmp % MOD;
      ans += MOD - sub;
      ans %= MOD;
    }
  }
  for (int i = 0; i < N; i++){
    for (auto edge : E[i]){
      int d = edge.first;
      int j = edge.second;
      if (d1[i] < d2[i] && d1[j] > d2[j] && d1[i] + d2[j] + d == d1[T]){
        long long tmp = dp1[i] * dp2[j] % MOD;
        long long sub = tmp * tmp % MOD;
        ans += MOD - sub;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}