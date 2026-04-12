#include <iostream>
#include <vector>

using ll = long long;


std::pair<int, int> loop_detect(std::vector<ll> &cum, int X, int M)
{
    std::vector<int> pos_memo(M, -1);
    
    ll a = X;
    ll sum = 0;

    int i;
    for (i = 0; i <= M; i++)
    {
        if (pos_memo[a] >= 0)
        {
            break;
        }
        else
        {
            pos_memo[a] = i;
            sum += a;
            cum[i+1] = sum;
            a = (a * a) % M;
        }
    }

    int l = pos_memo[a];
    if (pos_memo[a] < 0)
        l = 0;

    return {l, i};
}

int main()
{
    ll N;
    int X, M;
    std::cin >> N >> X >> M;

    std::vector<ll> rui(M+1, 0);
    auto [loop_l, loop_r] = loop_detect(rui, X, M);
    
    ll loop_range = loop_r - loop_l;
    ll loop_count = (N - loop_l) / loop_range;
    ll rest = (N - loop_l) % loop_range;
    ll loop_total = (rui[loop_r] - rui[loop_l]) * loop_count;
    ll ans = loop_total + rui[loop_l+rest];
    
    std::cout << ans << std::endl;
    return 0;
}
