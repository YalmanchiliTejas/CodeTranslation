#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define LL long long

const int MAXN = 200000 + 5;
const LL MOD = 1000000000 + 7;
LL a[MAXN];

int main()
{
    int N;
    LL sum, ans, mul;
    cin >> N;
    for (int i = 0; i < N; i ++){
        cin >> a[i];
    }
    sum = mul = ans = 0;
    for (int i = N - 1; i >= 0; i --){
        mul = (a[i] * sum) % MOD;
        sum = (sum + a[i]) % MOD;
        ans = (ans + mul) % MOD;
    }
    cout << ans;
    system("pause");
    return 0;
}