#include <bits/stdc++.h>
using namespace std;

//.define
// #define FILE_IN_OUT
#define RET(_x)    return cout << (_x) << '\n', 0;
#define all(_obj)  (_obj).begin(), (_obj).end()
#define loop(_n)   for (int i = 0; i < (_n); ++i)
#define sz(_obj)   static_cast<int>((_obj).size())
#ifdef SHJ_LOCAL
#define debug(_x)  std::cerr << (#_x) << " = " << (_x) << '\n' << std::flush;
#else
#define debug(_x)  {}
#endif
#define endl "\n"
template<typename P, typename Q>
P CeilDiv(P _dividend, Q _divider) {
    return static_cast<P>((_dividend - 1LL + _divider) / _divider);
}
template<typename Tp>
inline void outarr(Tp _begin, Tp _end, const char* _delim = " ") {
    for (Tp current = _begin; current != _end; ++current) {
        std::cout << *current << _delim;
    }
    std::cout << '\n';
}

//.constant
using ll  = long long;
using pii = std::pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = static_cast<const int>(1e9 + 7);

//.data
int Add(int x, int y) {
    x += y;
    return x < MOD ? x : x - MOD;
}

int Sub(int x, int y) {
    x -= y;
    return x >= 0 ? x : x + MOD;
}

int Mul(int x, int y) {
    return int(1LL * x * y % MOD);
}

//.code
int main() {
#ifdef FILE_IN_OUT
    std::ifstream cin ("input.txt",  std::ios::in);
    std::ofstream cout("output.txt", std::ios::out);
#else
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    int sum2 = 0;
    loop(n) {
        cin >> arr[i];
        sum = Add(sum, arr[i]);
        sum2 = Add(sum2, Mul(arr[i], arr[i]));
    }
    int ans = Sub(Mul(sum, sum), sum2);
    ans = Mul(ans, (MOD + 1) / 2);
    cout << ans << endl;

#ifdef FILE_IN_OUT
    cin.close();
    cout.close();
#endif
    return 0;
}