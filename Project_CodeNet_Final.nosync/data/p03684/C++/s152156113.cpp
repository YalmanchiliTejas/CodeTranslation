#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, M, X[100000], Y[100000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  set< pair< int, int > > toA, toB;
  for(int i = 0; i < N; i++) toA.emplace(X[i], i);
  for(int i = 0; i < N; i++) toB.emplace(Y[i], i);

  typedef pair< int, int > Pi;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  int64 ret = 0;
  que.emplace(0, 0);
  bool used[100000] = {};
  while(!que.empty()) {
    int aa = que.top().first;
    int p = que.top().second;
    que.pop();
    if(used[p]++) continue;
    ret += aa;

    pair< int, int > qq(X[p], p);
    {

      auto s = toA.lower_bound(qq);
      if(s != toA.begin()) que.emplace(X[p] - prev(s)->first, prev(s)->second);
      ++s;
      if(s != toA.end()) que.emplace(s->first - X[p], s->second);
    }

    {
      qq.first = Y[p];
      auto s = toB.lower_bound(qq);
      if(s != toB.begin()) que.emplace(Y[p] - prev(s)->first, prev(s)->second);
      ++s;
      if(s != toB.end()) que.emplace(s->first - Y[p], s->second);
    }
  }

  cout << ret << endl;
}
