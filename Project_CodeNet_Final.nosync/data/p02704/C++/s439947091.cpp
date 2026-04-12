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

tuple<vector<vector<int>>, bool>
Solve(int n, vector<Constraint> rows, vector<Constraint> cols) {
  vector<vector<int>> matrix = MakeVector2D(n, n, -1);
  vector<int> open_rows;
  vector<int> open_cols;
  for (int r = 0; r < n; r++) {
    if (rows[r] == ALL_ONE) {
      for (int c = 0; c < n; c++) {
        if (matrix[r][c] == 0) return {matrix, false};
        matrix[r][c] = 1;
      }
    } else if (rows[r] == ALL_ZERO) {
      for (int c = 0; c < n; c++) {
        if (matrix[r][c] == 1) return {matrix, false};
        matrix[r][c] = 0;
      }
    } else {
      open_rows.push_back(r);
    }
  }

  if (DEBUG) cout << "DEBUG 1" << endl;

  for (int c = 0; c < n; c++) {
    if (cols[c] == ALL_ONE) {
      for (int r = 0; r < n; r++) {
        if (matrix[r][c] == 0) return {matrix, false};
        matrix[r][c] = 1;
      }
    } else if (cols[c] == ALL_ZERO) {
      for (int r = 0; r < n; r++) {
        if (matrix[r][c] == 1) return {matrix, false};
        matrix[r][c] = 0;
      }
    } else {
      open_cols.push_back(c);
    }
  }

  if (DEBUG) cout << "DEBUG 2" << endl;
  if (DEBUG) cout << "open_rows: " << open_rows.size() << endl;
  if (DEBUG) cout << "open_cols: " << open_cols.size() << endl;

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
            
            if (rows[open_row] == ANY_ZERO && !bits[0]) return {matrix, false};
            if (rows[open_row] == ANY_ONE && !bits[1]) return {matrix, false};
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
    
    if (cols[open_col] == ANY_ZERO && !bits[0]) return {matrix, false};
    if (cols[open_col] == ANY_ONE && !bits[1]) return {matrix, false};

      }
    }
    return {matrix, true};
  }
  
  if (open_rows.size() >= 2 && open_cols.size() >= 2) {
    for (int ri = 0; ri < open_rows.size(); ri++) {
      for (int ci = 0; ci < open_cols.size(); ci++) {
        matrix[open_rows[ri]][open_cols[ci]] = (ri + ci) % 2;
      }
    }
    return {matrix, true};
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
    
    if (rows[open_row] == ANY_ZERO && !bits[0]) return {matrix, false};
    if (rows[open_row] == ANY_ONE && !bits[1]) return {matrix, false};
    return {matrix, true};
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
    
    if (cols[open_col] == ANY_ZERO && !bits[0]) return {matrix, false};
    if (cols[open_col] == ANY_ONE && !bits[1]) return {matrix, false};
    return {matrix, true};
  }

  cerr << "This path is not expected!" << endl;
  exit(1);
  return {matrix, false};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // cout << (1LL << 63) << endl;
  // cout << (1ULL << 63) << endl;

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
        if (val & (1ULL << bit)) {
          return ALL_ONE;
        } else {
          return ANY_ZERO;
        }
      } else {  // OR
        if (val & (1ULL << bit)) {
          return ANY_ONE;
        } else {
          return ALL_ZERO;
        }
      }
    };

    for (int i = 0; i < n; i++) {
      rows[i] = encode_fn(ss[i], us[i], b);
      cols[i] = encode_fn(ts[i], vs[i], b);
    }
    auto[matrix, is_valid] = Solve(n, rows, cols);
    if (!is_valid) {
      cout << -1 << endl;
      return 0;
    }

    if (DEBUG) cout << "BEFORE ADDITION" << endl;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (matrix[r][c] == 1) {
          ans[r][c] += 1ULL << b;
        }
      }
    }
    if (DEBUG) cout << "END ADDITION" << endl;
  }

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (c > 0) cout << " ";
      cout << ans[r][c];
    }
    cout << endl;
  }
}