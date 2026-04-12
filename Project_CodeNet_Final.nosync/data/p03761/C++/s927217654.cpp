#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>


template<
  typename Itr,
  typename F
>
static inline void
countSeq(const Itr& begin, const Itr& end, const F& f)
{
  int cnt = 0;
  auto c = *begin;
  for (auto itr = begin; itr != end; ++itr) {
    if (*itr != c) {
      f(c, cnt);
      c = *itr;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  f(c, cnt);
}


int
main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::map<char, int> charCntMap;

  // init
  std::string s;
  std::cin >> s;
  std::sort(std::begin(s), std::end(s));
  countSeq(std::cbegin(s), std::cend(s), [&charCntMap](auto c, auto cnt){
    charCntMap[c] = cnt;
  });

  for (int i = 0; i < n - 1; i++) {
    std::cin >> s;
    std::sort(std::begin(s), std::end(s));
    countSeq(std::cbegin(s), std::cend(s), [&s, &charCntMap](auto c, auto cnt){
      if (charCntMap.find(c) == std::cend(charCntMap)) {
        charCntMap[c] = 0;
      } else {
        charCntMap[c] = std::min(charCntMap[c], cnt);
      }
    });
    for (auto&& e : charCntMap) {
      if (s.find(e.first) == std::string::npos) {
        e.second = 0;
      }
    }
  }

  for (const auto& e : charCntMap) {
    for (decltype(e.second) i = 0; i < e.second; i++) {
      std::cout.put(e.first);
    }
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
