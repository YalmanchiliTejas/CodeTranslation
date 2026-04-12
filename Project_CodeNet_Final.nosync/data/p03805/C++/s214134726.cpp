#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define ALLR(X) (X).rbegin(), (X).rend()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

using namespace std;
 
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

int N, M;
bool visited[10];
vector<int> graph[10];

int cnt(int node, int howMany){
  if(howMany + 1 == N) return 1;

  int count = 0;
  visited[node] = true;
  for(int ele : graph[node]){
    if(visited[ele]) continue;
    count += cnt(ele, howMany + 1);
  }

  visited[node] = false;
  return count;
}

int main(){
  FAST_IO
  memset(visited, false, sizeof false);

  cin >> N >> M;
  for(int rep = 0, x, y; rep < M; ++rep){
    cin >> x >> y;
    graph[x].PB(y);
    graph[y].PB(x);
  }

  cout << cnt(1, 0);
  return 0;
}
