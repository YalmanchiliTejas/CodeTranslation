#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>

using namespace std;

const int MAX_N = 9;
int N, M;
bool g[MAX_N][MAX_N];

int main() {
   cin >> N >> M;
   map<int, int> ref;
   int a, b;
   memset(g, false, sizeof(g));
   for (int i = 0; i < M; i++) {
      cin >> a >> b;
      g[a][b] = true;
      g[b][a] = true;
   }
   vector<int> v(N);
   iota(v.begin(), v.end(), 1);
   int ans = 0;
   do {
      bool flg = true;
      if (v[0] != 1) continue;
      for (int i = 0; i < (int)v.size() - 1; i++) {
         if (!g[v[i]][v[i + 1]]) flg = false;
      }
      if (flg) ans++;
   } while ( next_permutation(v.begin(), v.end()) );
   cout << ans << endl;
   return 0;
}
