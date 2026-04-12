#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define debug3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define debugB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

template<typename T>
void printA(vector<T> &printArray, char between = ' ') {
   int paSize = printArray.size();
   for (int i = 0; i < paSize; i++) { cerr << printArray[i] << between;}
   if (between != '\n') {cerr << endl;}
}

// ------------------------------------------------------------------------------------------

int N, M;
vector<int> G[100];
bool visited[100];

int dfs(int from, int cnt) {
   if (cnt >= N-1) {
      return 1;
   }

   visited[from] = true;
   int ret = 0;
   for (int to : G[from]) {
      if (visited[to]) continue;
      // debug2(from, to)
      ret += dfs(to, cnt+1);
   }
   visited[from] = false;

   return ret;
}

int main() {
   cin >> N >> M;
   rep (i, M) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      G[a].push_back(b);
      G[b].push_back(a);
   }

   cout << dfs(0, 0) << endl;

   return 0;
}