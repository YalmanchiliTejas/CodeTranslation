#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

constexpr int SINT_MAX = std::numeric_limits<int>::max();
constexpr int SINT_MIN = std::numeric_limits<int>::min();

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

template<class T>
T choose(bool b, T t, T f)
{
    if (b) return t;
    else return f;    
}

const char *YesNo(bool b)
{
    return choose(b, "Yes", "No");
}

const char *YESNO(bool b)
{
    return choose(b, "YES", "NO");
}

template<class NumT>
NumT diffabs(NumT l, NumT r)
{
    if (l < r) return r-l;
    else return l-r;    
}

struct myinout_t {} io;

template<class T>
myinout_t &operator >>(myinout_t &my, T &i)
{
    cin >> i;
    return my;
}

myinout_t &operator >>(myinout_t &my, int &i)
{
    int r = scanf("%d", &i);
    if (r != 1) exit(EXIT_FAILURE);
    return my;
}

myinout_t &operator >>(myinout_t &my, ll &i)
{
    int r = scanf("%lld", &i);
    if (r != 1) exit(EXIT_FAILURE);
    return my;
}

template<class T>
myinout_t &operator <<(myinout_t &my, const T &i)
{
    cout << i;
    return my;
}

myinout_t &operator <<(myinout_t &my, int i)
{
    printf("%d", i);
    return my;
}

myinout_t &operator <<(myinout_t &my, ll i)
{
    printf("%lld", i);
    return my;
}

myinout_t &operator <<(myinout_t &my, double i)
{
    printf("%.20f", i);
    return my;
}

constexpr char BR = '\n';


///////////////////////////////////////////////////

int main()
{
    ll N;
    int X, M;
    io >> N >> X >> M;

    vector<int> bucMi(M+1, -1);
    vector<ll> rui(M+4, 0);
    
    ll a = X;
    ll sum = 0;

    int i;
    for (i = 0; i <= M; i++)
    {
        if (bucMi[a] >= 0)
        {
            break;
        }
        else
        {
            bucMi[a] = i;
            sum += a;
            rui[i+1] = sum;
            a = (a * a) % M;
        }
    }
    
    if (bucMi[a] < 0)
    {
        io << sum << BR;
        return 0;
    }

    ll loop_l = bucMi[a], loop_r = i;
    ll loop_range = loop_r - loop_l;
    ll loop_n = (N - loop_l) / loop_range;
    ll rest = (N - loop_l) % loop_range;

    ll ans = (rui[loop_r] - rui[loop_l]) * loop_n + rui[loop_l+rest];
    
    io << ans << BR;
    return 0;
}
