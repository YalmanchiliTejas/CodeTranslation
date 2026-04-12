#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <valarray>
#include <utility>
#include <tuple>
#include <cmath>
#include <random>

using ll = long long;

//各種nil
template <class T>
constexpr T nil = static_cast<T>(-1);

constexpr int nil_i = nil<int>;
constexpr int nil_ll = nil<ll>;
constexpr double nil_d = nil<double>;

//vector
template <class T>
using vec = std::vector<T>;

struct Vec2D
{
    int x, y;
};

struct TimePos
{
    int time;
    Vec2D pos;
};

int ManhattanDistance(Vec2D v1, Vec2D v2)
{
    using namespace std;
    return abs(v1.x - v2.x) + abs(v1.y - v2.y);
}

void solve()
{
    using namespace std;
    int r, g, b;
    cin >> r >> g >> b;
    
    if ((r * 100 + g * 10 + b) % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


}

int main()
{
    solve();
    return 0;
}