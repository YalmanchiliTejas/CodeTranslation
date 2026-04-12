/*
 * @Autor: valk
 * @Date: 2020-07-17 16:50:40
 * @LastEditTime: 2020-09-19 20:27:28
 * @Description: 如果邪恶  是华丽残酷的乐章 它的终场 我会亲手写上 晨曦的光 风干最后一行忧伤 黑色的墨 染上安详
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#define emplace_back push_back
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
const int seed = 12289;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;

int arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    ll sum = 0, rel = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for (int i = 1; i <= n; i++) {
        rel += 1LL * (sum -= arr[i]) % mod * arr[i] % mod;
        rel %= mod;
    }
    printf("%lld\n", rel);
    return 0;
}