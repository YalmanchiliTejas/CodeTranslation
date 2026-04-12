#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;

#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i, k, N) for (int i = k; i < N; i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(), (x).end()

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ll N;
    cin >> N;
    v a(N);
    rep(i, 0, N) cin >> a[i];
    priority_queue<ll> pq;
    rep(i, 0, N){
        pq.push(a[i]);
    }


    ll ans = 0;
    while (pq.top() + ans > N - 1){
        ll now = pq.top();pq.pop();
        ll t = (now+ans-N-2) > 0 ? (now+ans-N-2) / N + 1 : 1;
        ans += t;
        now -= t * (N+1);
        pq.push(now);
    }

    cout<<ans;
    return 0;
}