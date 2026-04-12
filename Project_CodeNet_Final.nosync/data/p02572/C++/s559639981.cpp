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

    long long plus = 0;
    rep(i, N)
    {
        int tmp;
        std::cin >> tmp;
        plus += tmp;
        plus = plus % MOD;
        A[i] = tmp;
    }

    ll ans = 0;
    rep(i, N-1)
    {
        plus -= A[i];

        // 10億7で割っているので底につくことがある 
        if(plus < 0)
        {
            plus += MOD;
        }
        ans += ( plus * A[i] ) % MOD;
        ans = ans % MOD;
    }
    
    std::cout << ans << std::endl;

    return 0;
}