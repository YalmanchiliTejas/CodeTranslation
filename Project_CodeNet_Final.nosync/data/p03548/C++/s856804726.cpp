#include <bits/stdc++.h>
using namespace std;

//.define
//#define FILE_IN_OUT
#define RET(_x)                       return std::cout << (_x), 0;
#define all(_obj)                     (_obj).begin(), (_obj).end()
#define fori(_iterator, _begin, _end) for (int _iterator = (_begin); _iterator < (_end); ++_iterator)
#define forr(_iterator, _begin, _end) for (int _iterator = (_begin); _iterator >= (_end); --_iterator)
#define loop(_n)                      for (int i = 0; i < (_n); ++i)
#define divCeil(_dividend, _divider)  (((_dividend) - 1LL + (_divider)) / (_divider))
#define sz(_obj)                      static_cast<int>((_obj).size())
#define endl                          "\n"
template<typename Tp>
inline void outarr(Tp _array, const std::size_t _N, const char* _delim = " ") {
    Tp end = _array + _N;
    for (Tp current = _array; current != end; ++current) {
        std::cout << *current << _delim;
    }
    std::cout << '\n';
}

//.constant
using ll  = std::int64_t;
using pii = std::pair<int, int>;
constexpr int INF = INT_MAX;
constexpr int MOD = 1e9 + 7;

//.data

//.code
int main() {
#ifdef FILE_IN_OUT
    std::ifstream сin  ("input.txt",  std::ios::in);
    std::ofstream сout ("output.txt", std::ios::out);
#else
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

   int x, y, z;
   cin >> x >> y >> z;

   x -= z;
   y += z;

   cout << x / y;

#ifdef FILE_IN_OUT
    cin.close();
    cout.close();
#endif
    return 0;
}