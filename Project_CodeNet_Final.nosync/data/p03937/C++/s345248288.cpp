#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
int h, w;
string s[8];

bool dfs(int x, int y){
  if(x == h - 1 && y == w - 1)return true;
  if(y < w - 1 && s[x][y+1] == '#' && dfs(x, y + 1))return true;
  if(x < h - 1 && s[x+1][y] == '#' && dfs(x + 1, y))return true;
  return false;
}

int main(int argc, char const* argv[])
{
  cin >> h >> w;
  for(int i = 0; i < h; i++)cin >> s[i];
  int sum = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '#')sum++;
    }
  }
  if(dfs(0, 0) && sum == h + w - 1)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
	return 0;
}
