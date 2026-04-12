#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1e9

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
    ll N, K;
    cin >> N >> K;
    
    ll ans = 0;
    if (K != 0) {
        for (ll i = K + 1; i <= N; ++i) {
            ans += (N / i) * (i - K);
            if (N % i >= K) {
                ans += (N % i) - K + 1;
            }
        }
    } else {
        ans = N * N;
    }
    
    cout << ans << endl;
    return 0;
}
