#include <bits/stdc++.h>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;

#define rep(idx, N) for (u64 idx = 0; idx < N; idx++)

int main() {
  string s;
  cin >> s;
  if (s[0] != s[1] || s[1] != s[2]) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}
