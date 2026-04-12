#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<list>
#include<deque>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<numeric>

using namespace std;

using ll = int64_t;

/// <summary>
/// 単純なcoutの時に使う
/// </summary>
#define co(a) cout<<a<<"\n"


/// <summary>
/// [beg, end)の範囲を，添え字indexでループするfor文に置換します
/// </summary>
#define rep(i,a) for(ll i=0; i<a; ++i)
#define reps(i, a, b) for(ll i = a; i < b; ++i)

/// <summary>
/// 迷路等で使う方向のベクトル
/// </summary>
const vector<ll> dx = { 0, 1, 0, -1 }, dy = { 1, 0, -1, 0 };

/// <summary>
/// デバッグ時に使う
/// </summary>
#define DEBUG(x)     std::cout << #x << " : " << x << "\n"

///////////////////////////////////////////////////////////////////////////

int main () {
	cin.tie (0);ios::sync_with_stdio (false);

	ll N, M;
    cin >> N >> M;

    if (N == M) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

