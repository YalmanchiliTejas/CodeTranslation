#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
string S;
int K, keta;

vector<vvint> memo(101, vvint(101, vint(2, -1)));

ll solve(int i, int num, bool smaller) //i桁目まで決めて、0でない数字がnum個あるようなやつ
{
    int x = S[i] - '0';
    if (i == keta)
    {
        memo[i][num][smaller] = num == 0;
        return num == 0;
    }
    if (memo[i][num][smaller] != -1)
    {
        return memo[i][num][smaller];
    }
    if (num == 0)
    {
        return memo[i][num][smaller] = 1;
    }

    if (smaller)
    {
        ll tmp = 0;
        tmp += solve(i + 1, num, true);
        tmp += solve(i + 1, num - 1, true) * 9;
        memo[i][num][true] = tmp;
        return tmp;
    }
    else
    {

        ll tmp = 0;
        if (x != 0)
            tmp += solve(i + 1, num, true);
        else
        {
            tmp += solve(i + 1, num, false);
            memo[i][num][false] = tmp;
            return tmp;
        }
        rep2(j, 1, x)
        {
            tmp += solve(i + 1, num - 1, true);
        }
        tmp += solve(i + 1, num - 1, false);
        memo[i][num][false] = tmp;
        return tmp;
    }
}

int main()
{

    cin >> S >> K;
    keta = S.size();
    cout << solve(0, K, false);
    return 0;
}