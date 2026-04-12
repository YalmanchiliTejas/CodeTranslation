/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
 
#define rep(i, n) for(int i = 0; i < n; i++)
 
//const long long INF = 1LL << 60;
const long long MOD = 1000000007;
using ll = long long;


int main()
{
    int N;
    std::cin >> N;
    std::vector<ll> A(N);

    std::vector<ll> ruisekiwa(N+1, 0);

    rep(i, N)
    {
        std::cin >> A[i];
        ruisekiwa[i+1] = ruisekiwa[i] + A[i];
    }

    long long ans = 0;
    rep(i, N)
    {
        //********************************************************
        // <EX>
        // in        = { 1, 3, 5, 7 }
        // ruisekiwa = { 0, 1, 4, 9, 16 }
        // i = 1, ruisekiwa = 15 = 16 - 1
        // i = 2, ruisekiwa = 12 = 16 - 4
        // i = 3, ruisekiwa = 7 = 16 - 9
        // i = 0, ruisekiwa = 0 = 16 -16
        //********************************************************
        long long sum = (ruisekiwa[N] - ruisekiwa[i+1] ) % MOD; // 頭からおしりまで - 今見ているところまで 
                                                                // iが大きくなるに従い、ruisekiwa[i+1]の大きさが増えるので
                                                                // sumの大きさは小さくなる
        ans += (A[i] * sum);
        ans %= MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}