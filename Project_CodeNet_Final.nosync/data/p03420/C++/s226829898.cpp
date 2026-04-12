#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    for(int b = K + 1; b <= N; b ++){
        int tmp = N / b * (b - K) + (K == 0 ? max(0, N % b - K) : max(0, N % b - K + 1));
        ans += 1L * tmp;
    }
    cout << ans << endl;

    return 0;
}
