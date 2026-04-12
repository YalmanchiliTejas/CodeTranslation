#pragma region include
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <bitset>
#include <cmath>
#include <tuple>
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
#define println(str) cout << str << endl;

#pragma endregion

#pragma region Utility
#pragma region 最大公約数
ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}
#pragma endregion

#pragma region 最小公倍数
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
#pragma endregion

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
    int N, M;
    cin >> N >> M;

    if (N == M)
    {
        Yes
    }
    No
}
