#include <string>
#include <iostream>
#include <stack>
#include <queue> // priority_queue も入ってる
#include <set>   // 要素数は size() で取得 multisetもある
#include <map>
#include <array> // sizeはコンパイル時定数で固定
#include <vector>
#include <numeric>   // accumulate, gcd
#include <algorithm> // count_ifに必要
#include <iomanip>   // cout << setprecision(15) << x で小数の出力精度を指定
#include <tuple>
#include <utility> //pair
#include <cmath>
#include <random>

using namespace std;
// 問題が起こるまでintは使用禁止2020-04-13
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <class InputIterator, class T>
bool contains_itr(InputIterator iterator, const T &value)
{
    if (find(iterator.begin(), iterator.end(), value) == iterator.end())
        return false;
    else
        return true;
}

template <class T>
bool contains_set(set<T> st, const T &value)
{
    if (st.find(value) == st.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class InputIterator>
auto sum(InputIterator iterator)
{
    return accumulate(iterator.begin(), iterator.end(), 0);
}

// endは排他的(exclusive)なので注意
vector<ll> range(ll begin, ll end)
{
    vector<ll> result;
    for (ll i = begin; i < end; ++i)
    {
        result.push_back(i);
    }
    return result;
}

random_device seed_gen;
mt19937 engine(seed_gen());
// 0, 1, 2 のどれかが得られる一様分布
// uniform_int_distribution<> dist(0, 2);
// cout << dist(engine) << endl;
// みたいに、先に確率分布を宣言して、そこにengineを与えて使う。

// =========ここまでテンプレ============

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> stepAt(m, -1);
    vector<ll> scoreAt(m, -1);

    // スタート地点への移動
    ll nowAt = x;
    ll step = 0;
    ll score = nowAt;

    // ここでは、歩き過ぎないようチェック
    // while文に入ると移動するので、まだ移動できる場合にだけtrue
    // この問題では、移動はn-1回なことに注意
    while (step < n - 1)
    {
        // 判定(先にステップ続行を書く。elseでループ部分をまとめて処理してstepとscoreを一気に増やす。)
        if (stepAt[nowAt] == -1)
        {
            // 記録(stepAtとscoreAtを更新)
            stepAt[nowAt] = step;
            scoreAt[nowAt] = score;

            // 移動(現在地と歩数とスコアを更新)
            step++;
            nowAt = (nowAt * nowAt) % m;
            score += nowAt;
        }
        else
        {
            // この瞬間、「ループのスタート地点に移動済み」で記録上書き前
            ll periodStep = step - stepAt[nowAt];
            ll periodScore = score - scoreAt[nowAt];
            // あと一歩も動かずに終わることがないようにする。最後1ループちょうど残ってても自力で歩く。
            // 1引いてから周期で割ればいいね
            ll remainingLoops = ((n - 1) - step - 1) / periodStep;
            step += remainingLoops * periodStep;
            score += remainingLoops * periodScore;
            // 訪問済みフラグを全て消します。
            stepAt = vector<ll>(m, -1);
            scoreAt = vector<ll>(m, -1);
            // あとは通常処理に戻って、歩数の限界まで歩きます。
        }
    }

    cout << score << endl;
    return 0;
}