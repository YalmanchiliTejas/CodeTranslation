#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

ll N, X;
ll a[51], p[51];

ll F(ll N, ll X) {
    if(N == 0) {
        if(X <= 0) return 0;
        return 1;
    }
    if(X <= 1 + a[N - 1]) {
        return F(N - 1, X - 1);
    }
    return p[N - 1] + 1 + F(N - 1, X - 2 - a[N - 1]);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    cin >> N >> X;
    a[0] = 1;
    p[0] = 1;
    rep(i, 1, N + 1) {
        a[i] = a[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    cout << F(N, X) << endl;

}
