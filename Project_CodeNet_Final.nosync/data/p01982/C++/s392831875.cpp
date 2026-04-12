#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <complex>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <limits>
#include <numeric>

using namespace std;
#define all(a) begin(a), end(a)

using ll = long long;
using ull = unsigned long long;
template <typename T>
using vec = vector<T>;
template <typename T>
using vec2 = vector<vec<T>>;

template <typename V, typename H>
void resize(vector<V> &vec, const H h)
{
    vec.resize(h);
}

template <typename V, typename H, typename... T>
void resize(vector<V> &vec, const H &h, const T... t)
{
    vec.resize(h);
    for (auto &v : vec)
    {
        resize(v, t...);
    }
}

template <typename V, typename T>
void fill(V &x, const T &val)
{
    x = val;
}

template <typename V, typename T>
void fill(vector<V> &vec, const T &val)
{
    for (auto &v : vec)
    {
        fill(v, val);
    }
}

struct pre_
{
    pre_()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(6);
    }
} pre__;

int main(void)
{
    while (1)
    {

        int n, l, r;

        int answer = 0;

        cin >> n >> l >> r;
        vector<int> get_input(n);
        if (n == 0 && l == 0 && r == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> get_input[i];
        }
        for (int x = l; x <= r; x++)
        {
            int tmp = -1;
            for (int i = 0; i < n; i++)
            {
                if (x % get_input[i] == 0)
                {
                    tmp = i;
                    break;
                }
            }
            if (tmp == -1)
            {
                if (n % 2 == 0)
                {
                    answer++;
                }
            }
            else
            {
                if ((tmp + 1) % 2 == 0)
                {
                }
                else
                {
                    answer++;
                }
            }
        }
        cout << answer << endl;
        
    }

    return 0;
}

