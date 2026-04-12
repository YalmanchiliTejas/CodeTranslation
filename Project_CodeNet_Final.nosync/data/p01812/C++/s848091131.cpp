#include <iostream>
#include <vector>
#include <queue>

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)

using namespace std;

const int kInf = 1e18;

struct Ver {
  int S;
  int d;
};

int n,m,k;
int black_room[16];
int v[100][100];
int black_room_id[100];

int d[1<<16];

template<typename T>
bool chmin(T& a, const T& b) {if (a > b) {a = b;return true;} return false;}

void Init(void) {
  rep(i,100) black_room_id[i] = -1;
}

void D_init (void) {
  rep(i,1<<m) {
    d[i] = -1;
  }
}

void PushQueue(int S, int dis, queue<Ver>& que) {
  rep (i,k) {
    int Snext = 0;
    rep (j,m) {
      if ((1 << j) & S) {
        int to = v[black_room[j]][i];
        if (black_room_id[to] < 0) continue;
        Snext = (Snext | (1 << black_room_id[to]));
      }
    }
    if (d[Snext] >= 0) {
      continue;
    }
    d[Snext] = dis;
    que.push((Ver){Snext,dis});
  }
}

void Solve(void) {
  D_init();
  queue<Ver> que;
  d[(1<<m)-1] = 0;
  que.push((Ver){(1<<m)-1, 0});

  while(!que.empty()) {
    Ver ver = que.front();
    que.pop();
    int S = ver.S;
    int d = ver.d;
    PushQueue(S, d+1, que);
  }
  cout << d[0] << endl;
}


signed main (void) {
  cin >> n >> m >> k; 
  Init();
  rep (i,m) {
    int d;
    cin >> d;
    d--;
    black_room_id[d] = i;
    black_room[i] = d;
  }
  rep (i,n) {
    rep (j,k) {
      cin >> v[i][j];
      v[i][j]--;
    }
  }
  Solve();
  return 0;
}
