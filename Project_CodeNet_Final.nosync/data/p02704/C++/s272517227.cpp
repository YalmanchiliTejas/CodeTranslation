#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;
constexpr char newl = '\n';

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= a; i--)
#define RF0(i,b) RFO(i,0,b)
#define F first
#define S second
#define debug(x) cout << #x << ": " << x << '\n';


// 一つの数につき行/列あわせて2種の制約をかける
// and, orそれぞれビットごとに強い制約か弱い制約のどちらかを持つ
// and 1: 全て1 / 0: N-1個まで1(最低1個0)
// or 1: 最低1個1 / 0: 全て0

enum BindType : u16 {
  And = 0, Or = 1
};

// 行または列の状態
struct LineState {
  BindType bindType;
  u64 bindValue;
  // ビットごとの利用数
  array<u16, 64> bitUses;
  
  int cellCount; // この行または列にあるセルの数

  LineState(int cellCount) : cellCount(cellCount)
  {
    F0R(i, 64) {
      bitUses[i] = 0;
    }
  }

  void addUses(u64 value) {
    F0R(i, 64) {
      if (value & 1) {
        bitUses[i]++;
      }
      value >>= 1;
    }
  }

  void subUses(u64 value) {
    F0R(i, 64) {
      if (value & 1) {
        bitUses[i]--;
      }
      value >>= 1;
    }
  }

  // or の弱制約 (1: 最低1個1)のうち現在まだ満たしていない部分を取得
  u64 restOr() {
    u64 result = 0;
    F0R(i, 64) {
      if (((bindValue >> i) & 1) != 0 && bitUses[i] == 0) {
        result |= (u64)1 << i;
      }
    }
    return result;
  }

  // 制約内で可能な限りビットの利用数を加算する
  // - 実際に加算できた数を返す
  u64 tryAddUses(u64 value) {
    if (bindType == BindType::Or) {
      value &= bindValue;
      addUses(value);
      return value;
    }

    u64 newValue = 0;
    F0R(i, 64) {
      if (((value >> i) & 1) != 0) {
        if (((bindValue >> i) & 1) != 0) {
          newValue |= (u64)1 << i;
        }
        else {
          // and 0 弱制約 は 利用数に空きが最低2あればOK
          if (bitUses[i] < cellCount - 1) {
            newValue |= (u64)1 << i;
          }
        }
      }
    }
    addUses(newValue);
    return newValue;
  }

  bool isValid() {
    if (bindType == BindType::Or) {
      F0R(i, 64) {
        if ((bindValue >> i) & 1) {
          // or 1: 弱 最低1個1
          if (bitUses[i] == 0) return false;
        }
        else {
          // or 0: 強 全て0
          if (bitUses[i] != 0) return false;
        }
      }
    }
    else {
      F0R(i, 64) {
        if ((bindValue >> i) & 1) {
          // and 1: 強 全て1
          if (bitUses[i] != cellCount) return false;
        }
        else {
          // and 0: 弱 最低1個0
          if (bitUses[i] == cellCount) return false;
        }
      }
    }
    return true;
  }
};

struct Cell {
  u64 min = 0;
  u64 max = UINT64_MAX;
  u64 value;

  constexpr void bindOr(u64 value) {
    max &= value;
  }
  constexpr void bindAnd(u64 value) {
    min |= value;
  }
  constexpr void bind(const LineState& ls) {
    if (ls.bindType == BindType::Or) {
      bindOr(ls.bindValue);
    }
    else {
      bindAnd(ls.bindValue);
    }
  }
  constexpr bool isValid() {
    return (min & (~max)) == 0;
  }
};

bool construct(int N, vector<LineState> &rowState,
  vector<LineState> &columnState, vector<vector<Cell>>& grid) {


  grid = vector<vector<Cell>>(N, vector<Cell>(N, Cell()));

  /*
  auto rMinOr = vector<u64>(N, 0);
  auto cMinOr = vector<u64>(N, 0);
  auto rMaxAnd = vector<u64>(N, UINT64_MAX);
  auto cMaxAnd = vector<u64>(N, UINT64_MAX);
  */

  F0R(r, N) {
    F0R(c, N) {
      grid[r][c].bind(rowState[r]);
      grid[r][c].bind(columnState[c]);
      if (!grid[r][c].isValid()) return false;
      //cout << grid[r][c].min << ' ' << grid[r][c].max << newl;

      // どちらもor制約ならmaxを、
      // どちらもand制約ならminを採用する
      if (rowState[r].bindType == BindType::Or &&
        columnState[c].bindType == BindType::Or) {
        grid[r][c].value = grid[r][c].max;
      }
      else if (rowState[r].bindType == BindType::And &&
        columnState[c].bindType == BindType::And) {
        grid[r][c].value = grid[r][c].min;
      }
      else {
        // and/or制約なら、とりあえずminにしてみる
        grid[r][c].value = grid[r][c].min;
      }

      /*
      rMinOr[r] |= grid[r][c].min;
      cMinOr[c] |= grid[r][c].min;
      rMaxAnd[r] &= grid[r][c].max;
      cMaxAnd[c] &= grid[r][c].max;
      */
      rowState[r].addUses(grid[r][c].value);
      columnState[c].addUses(grid[r][c].value);
    }
  }

  /*
  F0R(i, N) {
    if (S[i] != 0) {
      if ((rMinOr[i] & !U[i])!= 0) return false;
    }
    else {
      if ((rMaxAnd[i] & U[i]) != U[i]) return false;
    }
    if (T[i] != 0) {
      if ((cMinOr[i] & !V[i]) != 0) return false;
    }
    else {
      if ((cMaxAnd[i] & V[i]) != V[i]) return false;
    }
  }
  */

  // and/or制約をminにしたなら、orの弱制約を満たしていない箇所があるので
  // それをやっていく
  F0R(i, N) {
    auto rest = rowState[i].restOr();
    if (rest != 0) {
      F0R(j, N) {
        // 必要なビットのうち、まだこのcellで使われていないビット
        auto a = rest & ~grid[i][j].value;
        // or の時は既にmaxを使っているはずなので、必要ない
        if (columnState[j].bindType == BindType::And) {
          a = columnState[j].tryAddUses(a);
          grid[i][j].value |= a;
          rest ^= a;  // 使ったビットを0に
          if (rest == 0) break;
        }
      }
      if (rest != 0) {
        return false;
      }
      rowState[i].addUses(rowState[i].restOr());
    }

    rest = columnState[i].restOr();
    if (rest != 0) {
      F0R(j, N) {
        auto a = rest & ~grid[j][i].value;
        if (rowState[j].bindType == BindType::And) {
          a = rowState[j].tryAddUses(a);
          grid[j][i].value |= a;
          rest ^= a;  // 使ったビットを0に
          if (rest == 0) break;
        }
      }
      if (rest != 0) {
        return false;
      }
      columnState[i].addUses(columnState[i].restOr());
    }
  }

  // 制約を満たせているか確認
  F0R(i, N) {
    if (!rowState[i].isValid() || !columnState[i].isValid()) return false;
  }

  return true;
}

// INSERT ABOVE HERE
#if 1
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<LineState> rowState(N, LineState(N)), columnState(N, LineState(N));

  F0R(i, N) {
    u16 S; cin >> S;
    rowState[i].bindType = S != 0 ? BindType::Or : BindType::And;
  }
  F0R(i, N) {
    u16 T; cin >> T;
    columnState[i].bindType = T != 0 ? BindType::Or : BindType::And;
  }
  F0R(i, N) {
    cin >> rowState[i].bindValue;
  }
  F0R(i, N) {
    cin >> columnState[i].bindValue;
  }

  vector<vector<Cell>> grid;

  if (construct(N, rowState, columnState, grid)) {
    F0R(r, N) {
      F0R(c, N) {
        cout << grid[r][c].value << ' ';
      }
      cout << newl;
    }
  }
  else {
    cout << -1;
  }
}
#else
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  random_device rnd;
  mt19937 mt;
  mt.seed(rnd());
  uniform_int_distribution<> dst(0, UINT64_MAX);
  auto mat = vector<vector<u64>>(N, vector<u64>(N, 0));
  F0R(i, N) {
    F0R(j, N) {
      mat[i][j] = dst(mt);
    }
  }

  uniform_int_distribution<> zo(0, 1);
  vector<bool> S(N), T(N);
  vector<u64> U(N), V(N);
  F0R(i, N) {
    if (S[i] = zo(mt)) {
      u64 v = 0;
      F0R(j, N) {
        v |= mat[i][j];
      }
      U[i] = v;
    }
    else {
      u64 v = UINT64_MAX;
      F0R(j, N) {
        v &= mat[i][j];
      }
      U[i] = v;
    }

    if (T[i] = zo(mt)) {
      u64 v = 0;
      F0R(j, N) {
        v |= mat[j][i];
      }
      V[i] = v;
    }
    else {
      u64 v = UINT64_MAX;
      F0R(j, N) {
        v &= mat[j][i];
      }
      V[i] = v;
    }
  }

  F0R(i, N) cout << S[i] << ' ';
  cout << newl;
  F0R(i, N) cout << T[i] << ' ';
  cout << newl;
  F0R(i, N) cout << U[i] << ' ';
  cout << newl;
  F0R(i, N) cout << V[i] << ' ';
  cout << newl;
}
#endif
