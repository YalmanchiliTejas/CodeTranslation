#include <bits/stdc++.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;

class Counter {
private:
  bool used[128][128];
  u64 map_[128][128];
public:
  int X, Y;
  Counter() {
    for(int i = 0; i < 128; ++i) {
      for(int j = 0; j < 128; ++j) {
        used[i][j] = false;
      }
    }
  }
  void dfs_erase(int y, int x) {
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    if( not ( 0 <= y and y < Y and 0 <= x and x < X ) ) return;
    if( used[y][x] ) return;
    used[y][x] = true;
    for(int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if( not ( 0 <= ny and ny < Y and 0 <= nx and nx < X ) ) continue;
      if( map_[y][x] != map_[ny][nx] ) continue;
      if( used[ny][nx] ) continue;
      dfs_erase(ny, nx);
    }
  }
  int solve(u64 map[128][128]) {
    for(int i = 0; i < Y; ++i) {
      for(int j = 0; j < X; ++j) {
        used[i][j] = false;
      }
    }
    for(int i = 0; i < Y; ++i) {
      for(int j = 0; j < X; ++j) {
        map_[i][j] = map[i][j];
      }
    }
    int res = 0;
    for(int i = 0; i < Y; ++i) {
      for(int j = 0; j < X; ++j) {
        if( not used[i][j] ) {
          dfs_erase(i, j);
          res += 1;
        }
      }
    }
    return res;
  }
};

int main() {

  for(;;) {
    int n = 0;
    int l[128] = {};
    int t[128] = {};
    int r[128] = {};
    int b[128] = {};

    std::cin >> n;
    if( n == 0 ) break;
    for(int i = 0; i < n; ++i) {
      std::cin >> l[i] >> t[i] >> r[i] >> b[i];
    }

    std::vector<int> cx;
    std::vector<int> cy;
    cx.push_back(-1); cy.push_back(-1);
    for(int i = 0; i < n; ++i) {
      cx.push_back(l[i]);
      cx.push_back(r[i]);
      cy.push_back(t[i]);
      cy.push_back(b[i]);
    }

    std::sort(cx.begin(), cx.end());
    std::sort(cy.begin(), cy.end());    
    cx.erase(std::unique(cx.begin(), cx.end()), cx.end());
    cy.erase(std::unique(cy.begin(), cy.end()), cy.end());
    //std::cerr << " ttt " << cx.size() << " " << cy.size() << std::endl;

    u64 map[128][128] = {{}};

    for(int i = 0; i < 128; ++i) for(int j = 0; j < 128; ++j) map[i][j] = 0ULL;

    assert(n < 55);
    for(int i = 0; i < n; ++i) {
      int lt_x = 256, lt_y = 256, rb_x = 256, rb_y = 256;
      for(int j = 0; j < (int)cx.size(); ++j) {
        if( cx[j] == l[i] ) {
          lt_x = j;
        }
        if( cx[j] == r[i] ) {
          rb_x = j;
        }
      }
      assert( lt_x < rb_x );
      for(int j = 0; j < (int)cy.size(); ++j) {
        if( cy[j] == t[i] ) {
          lt_y = j;
        }
        if( cy[j] == b[i] ) {
          rb_y = j;
        }
      }
      assert( lt_y > rb_y );
      assert( 0 <= lt_x and lt_x < (int)cx.size() );
      assert( 0 <= lt_y and lt_y < (int)cy.size() );      
      assert( 0 <= rb_x and rb_x < (int)cx.size() );
      assert( 0 <= rb_y and rb_y < (int)cy.size() );      
      for(int y = lt_y - 1; y >= rb_y; --y) {
        for(int x = lt_x; x <= rb_x - 1; ++x) {
          map[y][x] |= (1ULL << i);
        }
      }
    }

    /*
    for(int y = 0; y < (int)cy.size(); ++y) {
      for(int x = 0; x < (int)cx.size(); ++x) {
        printf("%2lx ", map[y][x]);
      }
      putchar('\n');
    }
    */
    
    Counter counter;
    counter.X = cx.size();
    counter.Y = cy.size();
    std::cout << counter.solve(map) << std::endl;
  }
    
    
  return 0;
}