#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

string n;
int k;

// メモ化再帰
ll dp[110][2][4];

// digit桁目，現状がNと等しい数か，0以外を使用できる残り回数
ll rec(int digit, bool smaller, int k)
{
    if (k == 0)
        return 1;

    // 桁がnの長さよりも大きければ再帰を終了する
    if (digit >= n.size())
        return 0;

    // // 参照型でretを宣言
    // ll &ret = dp[digit][(int)smaller][k];

    // if (ret > 0)
    //     return ret;

    // ret = 0;

    if (dp[digit][(int)smaller][k] > 0)
    {
        return dp[digit][(int)smaller][k];
    }

    ll ret = 0;

    if (smaller)
    {
        ret += rec(digit + 1, true, k);           // 次の桁が0の時
        ret += rec(digit + 1, true, k - 1) * 9LL; // 次の桁が0以外の時
    }
    else
    {
        if (n[digit] == '0') // 次の桁が0しかあり得ない時
        {
            ret += rec(digit + 1, false, k);
        }
        else
        {
            ret += rec(digit + 1, true, k);                        // 0を使う時
            ret += rec(digit + 1, true, k - 1) * (n[digit] - '1'); // n[digit]より小さい数を使う時
            ret += rec(digit + 1, false, k - 1);                   // n[digit]と等しい数を使う時
        }
    }
    dp[digit][(int)smaller][k] = ret;
    return ret;
}

int main()
{
    cin >> n >> k;
    cout << rec(0, false, k) << endl;
    return 0;
}
