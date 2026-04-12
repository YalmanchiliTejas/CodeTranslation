#include <bits/stdc++.h>

#define MAX_NUM (1000000000 + 7)

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;

using namespace std;

template <typename T>
static inline void ArrayInput(vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cin >> *itr;
}

template <typename T>
static inline void ArrayPut(const vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cout << *itr << " ";
  cout << endl;
}

bool Sec_compare(pair<uint64_t, uint64_t> a, pair<uint64_t, uint64_t> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

u64 dec_dig(u64 num) {
  u64 res = 0;
  while (num > 0) {
    num /= 10;
    ++res;
  }
  return res;
}

u64 gcd(u64 a, u64 b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

int main() {
  cout << setprecision(15);
  string S;
  cin >> S;
  u32 flag = 0;
  if (S[0] == 'A' && S[1] == 'A' && S[2] == 'A') {
    cout << "No" << endl;
    return 0;
  }
  if (S[0] == 'B' && S[1] == 'B' && S[2] == 'B') {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  return 0;
}
