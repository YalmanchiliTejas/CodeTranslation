#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

ll N, X, M;

int main()
{
    cin >> N >> X >> M;

    // ループ判定用の連想配列
    map<ll, ll> m;

    // Anを試しに計算してみよう
    vector<ll> a(200000);
    a.at(0) = X;
    m[X]++;

    // ループ開始位置とループ終了の位置を保存
    ll loop_start = 0, loop_end = 0;
    // 1回目のループが終わる位置までの和
    ll sum1 = X;

    rep(1, i, 200000)
    {
        ll f = (a.at(i - 1) * a.at(i - 1)) % M;
        a.at(i) = f;
        m[f]++;
        // ループ箇所が見つかった
        if (m[f] > 1)
        {
            loop_end = i - 1;
            break;
        }
        sum1 += a.at(i);
    }

    // ループ開始までの和
    ll sum2 = 0;
    // ループ開始位置はどこですか
    rep(0, i, 200000)
    {
        if (a.at(i) == a.at(loop_end + 1))
        {
            loop_start = i;
            break;
        }
        sum2 += a.at(i);
    }

    // 答え
    ll ans = 0;

    // 残りの和をとる個数
    ll NN = N;

    // 1回目のループが終わる位a置(またはNがそれより小さい時はそこまで)の和を計算
    rep(0, i, min(N, loop_end + 1))
    {
        ans += a.at(i);
        NN--;
    }

    ans += (NN / (loop_end - loop_start + 1)) * (sum1 - sum2);

    rep(0, i, NN % (loop_end - loop_start + 1))
    {
        ll j = i + loop_start;
        ans += a.at(j);
    }

    cout << ans << endl;
}