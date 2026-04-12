#include <bits/stdc++.h>

#define LL long long
#define VI vector<int>
#define VB vector<bool>
#define VL vector<long long>
#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define EPS 1e-14

const std::string YES = "YES";
const std::string Yes = "Yes";
const std::string NO = "NO";
const std::string No = "No";

bool inside(int y, int x, int H, int W) { return 0 <= y && y < H && 0 <= x && x < W; }

// 4近傍（右, 下, 左, 上）
const std::vector<int> dy = { 0, -1, 0, 1 };
const std::vector<int> dx = { 1, 0, -1, 0 };

using namespace std;



int main() {
    int N;
    cin >> N;
    vector<pair<LL, LL>> l_r;

    LL max_ball = 0;
    LL min_ball = INT_MAX;
    FOR(i, 0, N) {
        LL l, r;
        cin >> l >> r;
        if (l > r) { swap(l, r); }

        max_ball = max(max_ball, r);
        min_ball = min(min_ball, l);
        l_r.emplace_back(make_pair(l, r));
    }
    sort(ALL(l_r));

    LL ans = LONG_LONG_MAX;
    // r_max = max_ball and r_min = min_ball
    {
        LL r_max = max_ball;
        LL r_min = min_ball;

        set<pair<LL, int>> blue_set;   // (value, index)    indexがINT_MAXなら入れ替えられない
        blue_set.insert({l_r[0].second, INT_MAX});
        // 仮に大きい方をblueとする(r_maxもはいっちゃうけど答えにはならないので無視できる)
        FOR(i, 1, N) {
            blue_set.insert({l_r[i].second, i});
        }
        while (true) {
            auto b_max = *blue_set.rbegin();
            LL diff = b_max.first - blue_set.begin()->first;
            ans = min(ans ,(r_max - r_min) * diff);

            // 入れ替え
            blue_set.erase(*blue_set.rbegin());
            if(b_max.second >= INT_MAX) {
                break;
            }
            blue_set.insert({l_r[b_max.second].first, INT_MAX});
        }
    }
    // r_max = max_ball and b_min = min_ball
    {
        LL r_max = max_ball;
        LL r_min = LONG_LONG_MAX;
        LL b_max = -1;
        LL b_min = min_ball;
        FOR(i, 0, N) {
            b_max = max(b_max, l_r[i].first);   // なるべく小さい方がいいのでfirstから探す
            r_min = min(r_min, l_r[i].second);  // なるべく大きい方がいいのでsecondから探す
        }
        ans = min(ans, (r_max - r_min) * (b_max - b_min));
    }

    cout << ans << endl;

    return 0;
}