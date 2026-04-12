#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 200010

ll N;
vector<ll> X, Y;

enum State { Suspend = 0, Red = 1, Blue = 2 };
vector< pair<ll, ll> > XY;  // first: val, second: index
vector<ll> pair_pos;    // XY[i] の、相方の XY での位置

signed main()
{
    cin >> N;
    X.resize(N);
    Y.resize(N);
    REP(i, N) {
        cin >> X[i] >> Y[i];
        // 小さい方を X にしておく
        if(X[i] > Y[i]) { swap(X[i], Y[i]); }
        XY.push_back(make_pair(X[i], i));
        XY.push_back(make_pair(Y[i], i));
    }
    SORT(XY);

    // pair_pos の作成
    pair_pos.assign(2 * N, 0);
    {
        vector< vector<ll> > table(N, vector<ll>());    // X or Y で位置 i にいるものの、 XY での位置
        REP(i, 2 * N) {
            table[XY[i].second].push_back(i);
        }
        REP(i, N) {
            pair_pos[table[i][0]] = table[i][1];
            pair_pos[table[i][1]] = table[i][0];
        }
    }

    const ll head = 0;
    const ll tail = 2 * N - 1;
    const ll xy_size = 2 * N;

    // パターン 1
    // 最小の値を赤に、最大の値を青にする場合
    // → 赤にできるだけ小さい値を、青にできるだけ大きい値を入れるのが最善
    ll r_min = XY[head].first;
    ll r_max = XY[pair_pos[tail]].first;
    ll b_min = XY[pair_pos[head]].first;
    ll b_max = XY[tail].first;
    // r_max/b_min を求める
    vector<ll> color(xy_size, Suspend);   // XY[i] はどっちの色か
    color[head] = Red;
    color[pair_pos[tail]] = Red;
    color[pair_pos[head]] = Blue;
    color[tail] = Blue;
    ll cnt = 2;
    REP(i, xy_size) {
        if(color[i] == Suspend) {
            color[i] = Red;
            color[pair_pos[i]] = Blue;
            r_max = max(r_max, XY[i].first);
            b_min = min(b_min, XY[pair_pos[i]].first);
            cnt++;
        }
    }
    assert(cnt == N);
    ll ans = (r_max - r_min) * (b_max - b_min);

    // パターン 2
    // 最小の値も最大の値も赤にする場合
    // → 青が取る区間を最小にするのが最善
    if(pair_pos[head] == tail) {
        // 最大と最小が同じ袋
        printf("%lld\n", ans);
        return 0;
    }

    ll l, r;
    auto Init = [&]() {
        l = min(pair_pos[head], pair_pos[tail]);
        r = max(pair_pos[head], pair_pos[tail]);
        r_min = XY[head].first;
        r_max = XY[tail].first;
        b_min = min(XY[pair_pos[head]].first, XY[pair_pos[tail]].first);
        b_max = max(XY[pair_pos[head]].first, XY[pair_pos[tail]].first);
        color.assign(xy_size, Suspend);
        color[head] = Red;
        color[tail] = Red;
        color[pair_pos[tail]] = Blue;
        color[pair_pos[head]] = Blue;
        cnt = 2;
    };

    Init();
    // パターン 2-1
    // まず [b_min, b_max] の中でまだ色が決まっていないやつを手当たり次第に取る
    if(cnt < N) {
        // とりあえずなるべく左側のもので充填してみる
        REP(i, 2 * N) {
            if(color[i] == Suspend) {
                color[i] = Blue;
                color[pair_pos[i]] = Red;
                cnt++;
                l = min(l, i);
                r = max(r, i);
                if(cnt == N) { break; }
            }
        }
    }
    assert(cnt == N);
    // 左から見て [l, r] を小さくできそうならそうする
    REP(i, xy_size) {
        assert(color[i] != Suspend);
        if(color[i] == Blue) {
            l = i;
            if(l < pair_pos[i] && pair_pos[i] < r) { swap(color[i], color[pair_pos[i]]); }
            else { break; }
        }
    }
    // 右から見て [l, r] を小さくできそうならそうする
    for(ll i = tail; i >= 0; --i) {
        assert(color[i] != Suspend);
        if(color[i] == Blue) {
            r = i;
            if(l < pair_pos[i] && pair_pos[i] < r) { swap(color[i], color[pair_pos[i]]); }
            else { break; }
        }
    }

    b_max = XY[r].first;
    b_min = XY[l].first;
    ans = min(ans, (r_max - r_min) * (b_max - b_min));

    // パターン 2-2
    // 一応両端を広げるパターンもやっておく
    Init();
    ll base_l = l;
    ll base_r = r;
    // まず [b_min, b_max] の中でまだ色が決まっていないやつを手当たり次第に取る
    for(ll i = base_l + 1; i < base_r; ++i) {
        if(color[i] == Suspend) {
            color[i] = Blue;
            color[pair_pos[i]] = Red;
            cnt++;
        }
        if(cnt == N) { break; }
    }
    // まだ色がついていない場所があるなら、なるべく青の max - min が
    // 大きくならないような範囲を探す
    while(cnt < N) {
        ll next_l = l;
        while(next_l >= 0) {
            if(color[next_l] == Suspend) { break; }
            next_l--;
        }
        ll next_r = r;
        while(next_r < xy_size) {
            if(color[next_r] == Suspend) { break; }
            next_r++;
        }
        if(next_l >= 0 && next_r < xy_size) {
            // どちらか近い方をとる
            ll sub_l = abs(XY[base_l].first - XY[next_l].first);
            ll sub_r = abs(XY[base_r].first - XY[next_r].first);
            if(sub_l < sub_r) {
                color[next_l] = Blue;
                color[pair_pos[next_l]] = Red;
                l = next_l;
            }
            else {
                color[next_r] = Blue;
                color[pair_pos[next_r]] = Red;
                r = next_r;
            }
            cnt++;
        }
        else if(next_l >= 0 && next_r >= xy_size) {
            // l をとる
            color[next_l] = Blue;
            color[pair_pos[next_l]] = Red;
            l = next_l;
            cnt++;
        }
        else if(next_l < 0 && next_r < xy_size) {
            // r をとる
            color[next_r] = Blue;
            color[pair_pos[next_r]] = Red;
            r = next_r;
            cnt++;
        }
        else {
            assert(false);
        }
    }
    assert(cnt == N);

    b_max = XY[r].first;
    b_min = XY[l].first;
    ans = min(ans, (r_max - r_min) * (b_max - b_min));

    printf("%lld\n", ans);

    return 0;
}
