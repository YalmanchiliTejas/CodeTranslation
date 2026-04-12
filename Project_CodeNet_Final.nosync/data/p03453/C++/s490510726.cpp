#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
const long long MOD = 1000000007;
vector <pair <long long, int> > edges[100000];
pair<long long, long long> d[100000][2];
void dijikstra_cost(int S, int N, int ind){
    for(int i = 0; i < N; i++){
      d[i][ind] = make_pair(LLONG_MAX, 0);
    }

    priority_queue < pair <long long, int> , vector <pair <long long, int> >, greater<pair <long long, int > > > pq;
    d[S][ind] = make_pair(0, 1);
    pq.push(make_pair(0, S));
    while(!pq.empty()){
        auto cur = pq.top();
        auto cur_cost = cur.first;
        auto cur_node = cur.second;
        pq.pop();
        if(d[cur_node][ind].first < cur_cost){
            continue;
        }

        for(int i = 0; i < edges[cur_node].size(); i++){
          auto next = edges[cur_node][i];
          auto next_node = next.second;
          auto cost = next.first;
          long long next_d = d[cur_node][ind].first + cost;
          if(d[next_node][ind].first >= next_d){
            if(d[next_node][ind].first > next_d){
              d[next_node][ind] = make_pair(next_d, d[cur_node][ind].second);
              pq.push(make_pair(next_d, next_node));
            } else {
              d[next_node][ind].second = (d[next_node][ind].second + d[cur_node][ind].second) % MOD;
            }
          }
        }
      }
}


int main(){
  int N;
  int M;
  cin >> N >> M;
  int S;
  int T;
  cin >> S >> T;
  S --;
  T --;
  for(int i = 0; i < M; i++){
    int U;
    int V;
    long long D;
    cin >> U >> V >> D;
    edges[U - 1].push_back(make_pair(D, V - 1));
    edges[V - 1].push_back(make_pair(D, U - 1));
  }
  
  dijikstra_cost(S, N, 0);
  dijikstra_cost(T, N, 1);

  long long coll_num = 0;
  long long ST_dst = d[T][0].first;
  for(int i = 0; i < N; i++){
    if(d[i][0].first + d[i][1].first == ST_dst){
      if(d[i][0].first == d[i][1].first){
        long long tmp = (((d[i][0].second * d[i][0].second) % MOD) * ((d[i][1].second * d[i][1].second) % MOD)) % MOD;
        coll_num = (coll_num + tmp) % MOD;
      }
      for(int j = 0; j < edges[i].size(); j++){
        int adj = edges[i][j].second;
        long long adj_cost = edges[i][j].first;
        if(d[i][0].first + adj_cost + d[adj][1].first == ST_dst){
          if(d[adj][0].first > d[adj][1].first && d[i][1].first > d[i][0].first){
            long long tmp = (((d[i][0].second * d[i][0].second) % MOD) * ((d[adj][1].second * d[adj][1].second) % MOD)) % MOD;
            coll_num = (coll_num + tmp) % MOD;
          }
        }
      }
    }
  }

  long long all_num = (d[T][0].second * d[S][1].second) % MOD;
  cout << (all_num - coll_num + MOD) % MOD << endl;
  return 0;
}
