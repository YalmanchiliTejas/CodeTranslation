// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

#define POS(x) cout<<((x)?"POSSIBLE":"IMPOSSIBLE")<<endl;
#define Pos(x) cout<<((x)?"Possible":"Impossible")<<endl;
#define YES(x) cout<<((x)?"YES":"NO")<<endl;
#define Yes(x) cout<<((x)?"Yes":"No")<<endl;
#define yes(x) cout<<((x)?"yes":"no")<<endl;


int h, w;
string f[8];
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> h >> w;
  int cnt = 0;
  for(int i = 0; i < h; i++) {
    cin >> f[i];
    for(int j = 0; j < w; j++) cnt += f[i][j] == '#';
  }
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  int ok = 0;
  while(q.size()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();
    if(f[y][x] == '.') continue;
    if(y+1 < h) q.emplace(y+1,x);
    if(x+1 < w) q.emplace(y,x+1);
    if(y == h-1 && x == w-1) ok = 1;
  }
  Pos(ok && cnt == h + w - 1);
  return 0;
}
