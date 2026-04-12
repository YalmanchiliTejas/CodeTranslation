#include <bits/stdc++.h>
 
#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define overload_rep(arg0, arg1, arg2, name, ...) name
#define all(box) box.begin(), box.end()
 
template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if (lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if (lhs > rhs) { lhs = rhs; return 1; } return 0; }

constexpr long long inf = 1ll << 60;

int main() {

    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> balls(N);
    rep (i, N) {
        int x, y;
        std::cin >> x >> y;
        if (x > y) std::swap(x, y);
        balls[i] = std::make_pair(x, y);
    }

    std::sort(all(balls));
    int min = balls[0].first, max = -1, pos = -1;
    rep (i, N) {
        if (chmax(max, balls[i].second)) {
            pos = i;
        }
    }

    long long answer = inf;
    // min, max を両方赤で塗る
    if (pos != 0) [&] {
        long long red = max - min;
        long long base_min, base_max;
        std::tie(base_min, base_max) = std::minmax(balls[0].second, balls[pos].first);
        if (N == 2) {
            chmin(answer, red * (base_max - base_min));
            return;
        }
        std::vector<long long> use1, use2;
        rep (i, N) {
            if (i == 0 || i == pos) continue;
            use1.push_back(balls[i].first);
            use2.push_back(balls[i].second);
        }
        chmin(answer, red * (std::max(base_max, use1.back()) - std::min(base_min, use1.front())));
        rep (i, N - 3) {
            chmin(base_min, use2[i]);
            chmax(base_max, use2[i]);
            chmin(answer, red * (std::max(base_max, use1.back()) - std::min(base_min, use1[i + 1])));
        }
        chmin(answer, red * (std::max(base_max, use2.back()) - std::min(base_min, use2.back())));
    } ();
    // min を赤, max を青で塗る
    [&] {
        long long red_min = min, red_max = balls[pos].first;
        long long blue_min = balls[0].second, blue_max = max;
        rep (i, N) {
            chmax(red_max, balls[i].first);
            chmin(blue_min, balls[i].second);
        }
        chmin(answer, (red_max - red_min) * (blue_max - blue_min));
    } ();

    std::cout << answer << '\n';
    return 0;

}
