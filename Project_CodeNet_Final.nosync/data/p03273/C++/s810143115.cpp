#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <iomanip>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int ctz(int x) { return __builtin_ctz(x); }
int clz(int x) { return __builtin_clz(x); }

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;
  vector <string> in(n);
  vi row(n, 1), col(m, 1);
  for(int i = 0; i < n; i++){
    cin >> in[i];
    if(in[i] == string(m, '.')){
      row[i] = 0;
    }
  }
  for(int j = 0; j < m; j++){
    string x = "";
    for(int i = 0; i < n; i++){
      x += in[i][j];
    }
    if(x == string(n, '.')){
      col[j] = 0;
    }
  }
  for(int i = 0; i < n; i++){
    if(!row[i]) continue;
    for(int j = 0; j < m; j++){
      if(!col[j]) continue;
      cout << in[i][j];
    }
    cout << "\n";
  }

}