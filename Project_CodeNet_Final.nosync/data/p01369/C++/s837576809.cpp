#include <bits/stdc++.h>
#include <cstdint>
#include <sys/time.h>

typedef std::int_fast32_t  s32;
typedef std::uint_fast32_t u32;
typedef std::int_fast64_t  s64;
typedef std::uint_fast64_t u64;

int main(void) {

  int isright[26] = {
    0, 0, 0, 0, 0, 0, 0,       // A ~ G
    1, 1, 1, 1, 1, 1, 1, 1, 1, // H ~ P
    0, 0, 0, 0,                // Q ~ T
    1,                         // U
    0, 0, 0,                   // V ~ X
    1,                         // Y
    0                          // Z
  };

  for(;;) {
    std::string str;
    std::cin >> str;
    if( str == "#" ) break;
    
    int n = str.size();

    std::vector<int> v;
    for(int i = 0; i < n; ++i) {
      v.push_back( isright[ str[i] - 'a' ] );
    }

    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::cout << (int)v.size() - 1 << std::endl;
  }
  
  return 0;
}