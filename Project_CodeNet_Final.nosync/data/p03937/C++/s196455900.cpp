# include <bits/stdc++.h>

# define rep(i, n) for (int i = 0; i < (int)(n); i++)
# define irep(i, n) for (int i = int(n) - 1; i >= 0; i--)
# define FOR(i, m, n) for (int i = int(m); i < (int)(n); i++)

using namespace std;
int H, W;
int nonzero = 0;
vector<int> di = {0, 1};
vector<int> dj = {1, 0};

// namespace utils
namespace utils{
  template <typename T> void print(vector<vector<T>> mat) {
    rep (i, mat.size()) {
      rep (j, mat[0].size()) cout << mat[i][j] << ' ';
      cout << endl;
    }
  }

  template <typename T> void print(vector<T> v) {
    rep (i, v.size()) cout << v[i] << ' ';
    cout << endl;
  }
// end namespace utils
}

bool restricted_dfs(vector<vector<char>> &A, int i, int j, int cnt) {
  // cout << cnt << "(" << nonzero << ")" << endl;
  if (H == i && W == j && cnt == nonzero) {
    return true;
  }


  rep (k, 2) {
    int next_i = i + di[k];
    int next_j = j + dj[k];


    if (next_i <= A.size()-1 && next_j <= A[0].size()-1 && \
        next_i >= 0 && next_j >= 0 && A[next_i][next_j] == '#') {
      return restricted_dfs(A, next_i, next_j, ++cnt); // return じゃないとダメな理由
    }
  }

  return false;
}

int main() {
  cin >> H >> W;

  vector<vector<char>> A(H);

  rep (i, H) {
    vector<char> row(W);
    rep (i, W) {
      cin >> row[i];
      if (row[i] == '#') nonzero++;
    }
    A[i] = row;
  }

  // utils::print(A);
  H--;
  W--;
  if (restricted_dfs(A, 0, 0, 1)) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
