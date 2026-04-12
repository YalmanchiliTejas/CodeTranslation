#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P; //cost to

#define max_V 100001
#define fs first
#define sc second

const int INF = 1 << 30;

vector<P> G[max_V];
bool used[max_V];

//出力：コスト
ll prim(){
  ll res = 0LL;
  priority_queue<P, vector<P>, greater<P>> que;

  //点0を集合Xに
  used[0] = true;
  for(int i = 0; i < (int)G[0].size(); i++){
    que.push(G[0][i]);
  }

  while(!que.empty()){
    P e = que.top();
    que.pop();
    int to = e.second;
    ll cost = e.first;

    if(!used[to]){
      used[to] = true;
      res += cost;
      for(int i = 0; i < (int)G[to].size(); i++){
        if(!used[G[to][i].second]){
          que.push(G[to][i]);
        }
      }
    }
  }

  return res;
}

bool cmp(const pair<pair<ll, ll>, int> &a, const pair<pair<ll, ll>, int> &b){
  return a.fs.sc < b.fs.sc;
}

int main(){
  int N;
  cin >> N;
  pair<pair<ll, ll>, int> p[N];
  for(int i = 0; i < N; i++){
    cin >> p[i].first.first >> p[i].first.second;
    p[i].second = i;
  }

  sort(p, p + N);
  /*for(int i = 0; i < N; i++){
    cout << p[i].fs.fs << " " << p[i].fs.sc << " " << p[i].sc << endl;
  }*/
  for(int i = 0; i < N - 1; i++){
    ll dist = min(abs(p[i].fs.fs - p[i+1].fs.fs), abs(p[i].fs.sc - p[i+1].fs.sc));
    G[p[i].sc].push_back(P(dist, p[i + 1].sc));
    G[p[i + 1].sc].push_back(P(dist, p[i].sc));
  }

  sort(p, p + N, cmp);
  /*for(int i = 0; i < N; i++){
    cout << p[i].fs.fs << " " << p[i].fs.sc << " " << p[i].sc << endl;
  }*/
  for(int i = 0; i < N - 1; i++){
    ll dist = min(abs(p[i].fs.fs - p[i+1].fs.fs), abs(p[i].fs.sc - p[i+1].fs.sc));
    G[p[i].sc].push_back(P(dist, p[i + 1].sc));
    G[p[i + 1].sc].push_back(P(dist, p[i].sc));
  }

  cout << prim() << endl;
  return 0;
}
