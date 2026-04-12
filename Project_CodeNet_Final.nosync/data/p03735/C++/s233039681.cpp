#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
const int64 INF = 1LL << 60;
 
int main()
{
  int64 N, X[200000], Y[200000];
 
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    if(X[i] > Y[i]) swap(X[i], Y[i]);
  }
 
  int64 ret = INF;
 
  int64 latte = INF, malta = -INF;
  for(int i = 0; i < N; i++) {
    latte = min(latte, X[i]);
    malta = max(malta, Y[i]);
  }
 
  int64 beet = latte, ukuku = malta;
  for(int i = 0; i < N; i++) {
    beet = max(beet, X[i]);
    ukuku = min(ukuku, Y[i]);
  }
 
  ret = min(ret, (beet - latte) * (malta - ukuku));
 
  vector< pair< int64, int64 > > vs;
  for(int i = 0; i < N; i++) {
    vs.emplace_back(X[i], Y[i]);
  }
  sort(begin(vs), end(vs));
 
  int64 len = max(beet, malta) - min(ukuku, latte);
  latte = max(beet, malta), malta = vs.back().first;
  for(int i = 0; i < N; i++) {
    ret = min(ret, len * (malta - min(latte, i == N ? INF : vs[i].first)));
    latte = min(latte, vs[i].second);
    malta = max(malta, vs[i].second);
  }
  cout << ret << endl;
}