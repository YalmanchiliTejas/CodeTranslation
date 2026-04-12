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
    vector<LL> L(N), R(N);
    vector<pair<int, int>> P;

    LL max_ball = 0;
    LL min_ball = INT_MAX;
    FOR(i, 0, N) {
        cin >> L[i] >> R[i];
        max_ball = max(max_ball, max(L[i], R[i]));
        min_ball = min(min_ball, min(L[i], R[i]));
        P.emplace_back(make_pair(min(L[i], R[i]), max(L[i], R[i])));
    }
    sort(ALL(P));

    LL ans = LONG_LONG_MAX;
    // r_max = max_ball and r_min = min_ball
    {
        LL r_max = max_ball;
        LL r_min = min_ball;

        set<pair<LL, int>> S;
        S.insert({P[0].second,1000000});
        FOR(i,0, N) {
            if(i) {
                S.insert({P[i].second,i});
            }
        }
        while(1) {
            LL diff = S.rbegin()->first - S.begin()->first;
            ans = min(ans ,(r_max - r_min) * diff);

            auto a = *S.rbegin();
            S.erase(*S.rbegin());

            if(a.second>=1000000) {
                break;
            }
            S.insert({P[a.second].first,1000000});
        }
    }
    // r_max = max_ball and b_min = min_ball
    {
        LL r_max = max_ball;
        LL r_min = LONG_LONG_MAX;
        LL b_max = P[N-1].first;
        LL b_min = min_ball;
        FOR(i, 0, N) {
            r_min = min<LL>(r_min, P[i].second);
        }
        ans = min(ans, (r_max - r_min) * (b_max - b_min));
    }

    cout << ans << endl;

    return 0;
}