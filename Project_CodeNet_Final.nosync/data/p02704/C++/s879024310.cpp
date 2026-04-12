#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

constexpr int DEBUG = 0;
constexpr int NUM_BITS = 64;

template<typename T>
vector<vector<T>> MakeVector2D(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

enum Constraint {
  ALL_ZERO,
  ANY_ZERO,
  ALL_ONE,
  ANY_ONE
};

optional<vector<vector<int>>>
Solve(int n, vector<Constraint> rows, vector<Constraint> cols) {
  vector<vector<int>> matrix = MakeVector2D(n, n, -1);
  vector<int> open_rows;
  vector<int> open_cols;

  auto fill_row = [&](int r, int v) -> bool {
    for (int c = 0; c < n; c++) {
      if (matrix[r][c] == -1) matrix[r][c] = v;
      else if (matrix[r][c] != v) return false;
    }
    return true;
  };

  for (int r = 0; r < n; r++) {
    if (rows[r] == ALL_ONE) {
      if (!fill_row(r, 1)) return nullopt;
    } else if (rows[r] == ALL_ZERO) {
      if (!fill_row(r, 0)) return nullopt;
    } else {
      open_rows.push_back(r);
    }
  }

  auto fill_col = [&](int c, int v) -> bool {
    for (int r = 0; r < n; r++) {
      if (matrix[r][c] == -1) matrix[r][c] = v;
      else if (matrix[r][c] != v) return false;
    }
    return true;
  };

  for (int c = 0; c < n; c++) {
    if (cols[c] == ALL_ONE) {
      if (!fill_col(c, 1)) return nullopt;
    } else if (cols[c] == ALL_ZERO) {
      if (!fill_col(c, 0)) return nullopt;
    } else {
      open_cols.push_back(c);
    }
  }

  if (open_rows.size() == 0 || open_cols.size() == 0) {
    if (open_rows.size() > 0) {
      for (int open_row : open_rows) {
            vector<int> bits(2);
            for (int c = 0; c < n; c++) {
              if (rows[open_row] == ANY_ZERO) {
                if (matrix[open_row][c] == -1) matrix[open_row][c] = 0;
              } else if (rows[open_row] == ANY_ONE) {
                if (matrix[open_row][c] == -1) matrix[open_row][c] = 1;
              }
              if (matrix[open_row][c] == 0) bits[0] = 1;
              if (matrix[open_row][c] == 1) bits[1] = 1;
            }
            
            if (rows[open_row] == ANY_ZERO && !bits[0]) return nullopt;
            if (rows[open_row] == ANY_ONE && !bits[1]) return nullopt;
      }
    } else if (open_cols.size() > 0) {
      for (int open_col : open_cols) {

    vector<int> bits(2);
    for (int r = 0; r < n; r++) {
      if (cols[open_col] == ANY_ZERO) {
        if (matrix[r][open_col] == -1) matrix[r][open_col] = 0;
      } else if (cols[open_col] == ANY_ONE) {
        if (matrix[r][open_col] == -1) matrix[r][open_col] = 1;
      }
      if (matrix[r][open_col] == 0) bits[0] = 1;
      if (matrix[r][open_col] == 1) bits[1] = 1;
    }
    
    if (cols[open_col] == ANY_ZERO && !bits[0]) return nullopt;
    if (cols[open_col] == ANY_ONE && !bits[1]) return nullopt;

      }
    }
    return matrix;
  }
  
  if (open_rows.size() >= 2 && open_cols.size() >= 2) {
    for (int ri = 0; ri < open_rows.size(); ri++) {
      for (int ci = 0; ci < open_cols.size(); ci++) {
        matrix[open_rows[ri]][open_cols[ci]] = (ri + ci) % 2;
      }
    }
    return matrix;
  } else if (open_rows.size() == 1) {
    int open_row = open_rows[0];
    for (int open_col : open_cols) {
      vector<int> bits(2);
      for (int r = 0; r < n; r++) {
        if (matrix[r][open_col] == 0) bits[0] = 1;
        if (matrix[r][open_col] == 1) bits[1] = 1;
      }
      if (cols[open_col] == ANY_ZERO) {
        if (!bits[0]) matrix[open_row][open_col] = 0;
      } else if (cols[open_col] == ANY_ONE) {
        if (!bits[1]) matrix[open_row][open_col] = 1;
      } else {
        cerr << "This path should not happen!" << endl;
        exit(1);
      }
    }

    vector<int> bits(2);
    for (int c = 0; c < n; c++) {
      if (rows[open_row] == ANY_ZERO) {
        if (matrix[open_row][c] == -1) matrix[open_row][c] = 0;
      } else if (rows[open_row] == ANY_ONE) {
        if (matrix[open_row][c] == -1) matrix[open_row][c] = 1;
      }
      if (matrix[open_row][c] == 0) bits[0] = 1;
      if (matrix[open_row][c] == 1) bits[1] = 1;
    }
    
    if (rows[open_row] == ANY_ZERO && !bits[0]) return nullopt;
    if (rows[open_row] == ANY_ONE && !bits[1]) return nullopt;
    return matrix;
  } else {
    // open_cols.size() == 1
    int open_col = open_cols[0];
    for (int open_row : open_rows) {
      vector<int> bits(2);
      for (int c = 0; c < n; c++) {
        if (matrix[open_row][c] == 0) bits[0] = 1;
        if (matrix[open_row][c] == 1) bits[1] = 1;
      }
      if (rows[open_row] == ANY_ZERO) {
        if (!bits[0]) matrix[open_row][open_col] = 0;
      } else if (rows[open_row] == ANY_ONE) {
        if (!bits[1]) matrix[open_row][open_col] = 1;
      } else {
        cerr << "This path should not happen!" << endl;
        exit(1);
      }
    }

    vector<int> bits(2);
    for (int r = 0; r < n; r++) {
      if (cols[open_col] == ANY_ZERO) {
        if (matrix[r][open_col] == -1) matrix[r][open_col] = 0;
      } else if (cols[open_col] == ANY_ONE) {
        if (matrix[r][open_col] == -1) matrix[r][open_col] = 1;
      }
      if (matrix[r][open_col] == 0) bits[0] = 1;
      if (matrix[r][open_col] == 1) bits[1] = 1;
    }
    
    if (cols[open_col] == ANY_ZERO && !bits[0]) return nullopt;
    if (cols[open_col] == ANY_ONE && !bits[1]) return nullopt;
    return matrix;
  }

  cerr << "This path is not expected!" << endl;
  exit(1);
  return nullopt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> ss(n);
  vector<int> ts(n);
  vector<uint64> us(n);
  vector<uint64> vs(n);
  for (int i = 0; i < n; i++) {
    cin >> ss[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> ts[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> us[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
  }

  vector<vector<uint64>> ans = MakeVector2D(n, n, 0ULL);
  for (int b = 0; b < NUM_BITS; b++) {
    vector<Constraint> rows(n);
    vector<Constraint> cols(n);

    auto encode_fn = [](int constraint_type, uint64 val, int bit) -> Constraint {
      if (constraint_type == 0) {  // AND
        return (val & (1ULL << bit)) ? ALL_ONE : ANY_ZERO;
      } else {  // OR
        return (val & (1ULL << bit)) ? ANY_ONE : ALL_ZERO;
      }
    };

    for (int i = 0; i < n; i++) {
      rows[i] = encode_fn(ss[i], us[i], b);
      cols[i] = encode_fn(ts[i], vs[i], b);
    }
  
    auto optional_matrix = Solve(n, rows, cols);
    if (!optional_matrix) {
      cout << -1 << endl;
      return 0;
    }

    auto matrix = *optional_matrix;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (matrix[r][c] == 1) {
          ans[r][c] += 1ULL << b;
        }
      }
    }
  }

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (c > 0) cout << " ";
      cout << ans[r][c];
    }
    cout << endl;
  }
}
