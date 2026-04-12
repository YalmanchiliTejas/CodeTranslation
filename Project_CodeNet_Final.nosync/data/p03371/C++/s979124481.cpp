#pragma region include
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#pragma endregion
using namespace std;

#pragma region 定数
#define INF_VAL (2147483647 - 1)
#define INF_VAL_MINUS -INFVAL
#pragma endregion

#pragma region マクロ
// 型
#define ll long long

// 配列の長さを取得する(ただし関数内ではポインタサイズに注意)
#define SIZE_OF_ARRAY(array) sizeof(array) / sizeof(*array)

// for文
#define forn(i, size) for (long long(i) = 0; (i) < (size); (i)++)
#define for0(size) for (long(i) = 0; (i) < (size); (i)++)

// ソート
#define Sort(array, length) sort(array, array + length)
#define SortDESC(array, length, type_name) sort(array, array + length, std::greater<type_name>())

// 配列の最大値、最小値取得
#define MAX_OF_ARRAY(array, length) *max_element(array, array + length)
#define MIN_OF_ARRAY(array, length) *min_element(array, array + length)

// 結果出力系
#define YES                    \
    {                          \
        cout << "YES" << endl; \
        return 0;              \
    }
#define NO                    \
    {                         \
        cout << "NO" << endl; \
        return 0;             \
    }
#define Yes                    \
    {                          \
        cout << "Yes" << endl; \
        return 0;              \
    }
#define No                    \
    {                         \
        cout << "No" << endl; \
        return 0;             \
    }
#pragma endregion

#pragma region Utility
#pragma region 配列要素の合計値を取得
template <typename T>
T getSum(T array[], int length)
{
    T sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum;
}
#pragma endregion

#pragma region ToString(int)
string ToString(int i)
{
    char buffer[1000];
    sprintf(buffer, "%d", i);
    return string(buffer);
}
#pragma endregion

#pragma region 10進数からN進数(<= 10) へ変換
string convertToN(long n, int base)
{
    string ans = "";
    while (n != 0)
    {
        int temp = n % base; // 1桁取得
        ans = ToString(temp) + ans;
        n /= base;
    }
    return ans;
}
#pragma endregion

#pragma region 連想配列のkeyが存在するか
template <typename T>
bool containsKey(map<string, T> map, string key)
{
    if (map.count(key) == 0)
    {
        return false;
    }
    return true;
}
#pragma endregion
#pragma endregion

int main()
{
    // 標準入力から値を取得
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int n_A = 0, n_B = 0, n_AB = 0;

    // 先にABピザを最大限買った場合を求め、
    // ABピザを2枚ずつ減らしていく
    n_AB = max(X, Y) * 2;
    ll ans = n_AB * C;

    for (n_AB -= 2; n_AB >= 0; n_AB -= 2)
    {
        // 足りないAピザを求める
        n_A = max(0, X - (n_AB / 2));

        // 足りないBピザを求める
        n_B = max(0, Y - (n_AB / 2));

        // 金額計算
        ans = min(ans, (ll)A * n_A + (ll)B * n_B + (ll)C * n_AB);
    }

    // 結果出力
    printf("%lld\n", ans);
}
