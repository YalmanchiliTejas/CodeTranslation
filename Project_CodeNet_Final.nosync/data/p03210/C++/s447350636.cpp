#include <cstddef>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <limits>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <valarray>
#include <utility>
#include <tuple>
#include <cmath>
#include <memory>
#include <random>
#include <fstream>
#include <locale>

using ll = long long;
using ull = unsigned long long;

//vector
template <class T>
using vec = std::vector<T>;

template <class T>
using vvec = vec<vec<T>>;

constexpr std::size_t operator""_sz(ull n) { return std::size_t(n); }

int main()
{
    using namespace std;

    int x;
    cin >> x;

    if (x == 7 || x == 5 || x == 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
