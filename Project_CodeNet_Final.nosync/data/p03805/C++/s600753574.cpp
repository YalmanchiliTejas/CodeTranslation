#include <bits/stdc++.h>
using namespace std;

//long long
using ll = long long;

// pair<int, int>
using PII = pair<int, int>;

//最大値、mod
const int MOD = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;

//出力系
#define print(x) cout << x << endl
#define prints(x) cout << fixed << setprecision(10) << x << endl
#define printc(x) cout << setw(2) << setfill('0') << x << endl;
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

// a = max(a, b), a = min(a, b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};





int cnt;
int H, W, N;
char c[1010][1010];
int sx[10];
int sy[10];
ll ans = 0;
int d[1010][1010];

int bfs(int y, int x){
  queue<PII>que;
  REP(i, H)REP(j, W) d[i][j] = INF;
  d[y][x] = 0;
  que.push(PII(y, x));
  while(!que.empty()){
    PII p = que.front(); que.pop();
    if(p.first == sy[cnt] && p.second == sx[cnt]) break;
    REP(i, 4){
      int ny = p.first + dy[i]; int nx = p.second + dx[i];
      if(nx >= 0 && nx < W && ny >= 0 && ny < H && c[ny][nx] != 'X' && d[ny][nx] == INF){
        que.push(PII(ny, nx));
        d[ny][nx] = d[p.second][p.first] + 1;
      }
    }
  }
  return d[sy[cnt]][sx[cnt]];
}


int main(){
  bool d[10][10] = {false};
  int N, M;
  cin >> N >> M;
  REP(i, M){
    int a, b;
    cin >> a >> b;
    --a; --b;
    d[a][b] = true;
    d[b][a] = true;
  }
  vector<int>retu(N);
   REP(i, N) retu[i] = i;
  int ans = 0;
  do{
    if(retu[0] != 0) break;
    bool flag = true;
    REP(i, N - 1){
      int x = retu[i];
      int y = retu[i + 1];
      if(!d[x][y]) flag = false;
    }
    if(flag) ans++;
  }while(next_permutation(all(retu)));
print(ans);
}
