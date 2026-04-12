#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using Matrix=std::vector<std::vector<int>>;

void rotate(Matrix &a) {
  size_t r, c, size;
  int angle;
  scanf("%zu %zu %zu %d", &r, &c, &size, &angle);
  --r, --c;

  if (angle == 0 || angle == 360) return;  // ???
  Matrix b(size, std::vector<int>(size));
  for (size_t i=0; i<size; ++i)
    for (size_t j=0; j<size; ++j)
      b[i][j] = a[r+i][c+j];

  for (size_t i=0; i<size; ++i) {
    for (size_t j=0; j<size; ++j) {
      if (angle == 90) {
        a[r+i][c+j] = b[size-j-1][i];
      } else if (angle == 180) {
        a[r+i][c+j] = b[size-i-1][size-j-1];
      } else if (angle == 270) {
        a[r+i][c+j] = b[j][size-i-1];
      }
    }
  }
}

void reversal(Matrix &a) {
  size_t r, c, size;
  scanf("%zu %zu %zu", &r, &c, &size);
  --r, --c;

  for (size_t i=0; i<size; ++i)
    for (size_t j=0; j<size; ++j)
      a[r+i][c+j] ^= 1;
}

void left_shift(Matrix &a) {
  size_t r;
  scanf("%zu", &r);
  --r;

  int tmp=a[r][0];
  for (size_t j=1; j<a.size(); ++j) 
    a[r][j-1] = a[r][j];

  a[r].back() = tmp;
}

void right_shift(Matrix &a) {
  size_t r;
  scanf("%zu", &r);
  --r;

  int tmp=a[r].back();
  for (size_t j=a.size()-1; j>=1; --j)
    a[r][j] = a[r][j-1];

  a[r][0] = tmp;
}

const size_t di[]={size_t(-1), 0, 1, 0};
const size_t dj[]={0, size_t(-1), 0, 1};

void island_reversal(Matrix &a) {
  size_t r, c;
  scanf("%zu %zu", &r, &c);
  --r, --c;

  int par=a[r][c];
  std::queue<std::pair<size_t, size_t>> q;
  q.emplace(r, c);
  while (!q.empty()) {
    size_t i=q.front().first, j=q.front().second;
    q.pop();
    if (a[i][j] != par) continue;
    a[i][j] ^= 1;

    for (int k=0; k<4; ++k) {
      size_t ni=i+di[k], nj=j+dj[k];
      if (!(ni < a.size() && nj < a.size())) continue;
      if (a[ni][nj] != par) continue;
      q.emplace(ni, nj);
    }
  }
}
        

int main() {
  size_t n, m;
  scanf("%zu %zu", &n, &m);

  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  for (size_t i=0; i<n; ++i) {
    for (size_t j=0; j<n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for (size_t i=0; i<m; ++i) {
    int op;
    scanf("%d", &op);

    switch (op) {
    case 0:
      rotate(a);
      break;

    case 1:
      reversal(a);
      break;

    case 2:
      left_shift(a);
      break;

    case 3:
      right_shift(a);
      break;

    case 4:
      island_reversal(a);
      break;
    }

  // for (size_t i=0; i<n; ++i)
  //   for (size_t j=0; j<n; ++j)
  //     fprintf(stderr, "%d%c", a[i][j], j+1<n? ' ':'\n');
  }

  for (size_t i=0; i<n; ++i)
    for (size_t j=0; j<n; ++j)
      printf("%d%c", a[i][j], j+1<n? ' ':'\n');
}

