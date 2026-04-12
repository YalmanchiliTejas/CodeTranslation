#include <iostream>
#include <vector>
#include <string>

using namespace std;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main(int argc, char* argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  i32 N, M;
  cin >> N >> M;
  
  if(M == N) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
