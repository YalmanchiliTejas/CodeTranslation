#include <iostream>
#include <vector>

using namespace std;

long long search_patty(long long ans, int n, long long res, vector<long long> num_layer, vector<long long> num_patty) {
    // cout << ans << ' ' << n << ' ' << res << endl;
    if (res <= 1) return ans;
    else if (res < num_layer[n - 1] + 1) {
        ans = search_patty(ans, n - 1, res - 1, num_layer, num_patty);
        return ans;
    } else if (res < num_layer[n] - 1) {
        ans += num_patty[n - 1];
        res -= num_layer[n - 1] + 1;
        if (!res) return ans;
        else ans = search_patty(ans + 1, n - 1, res - 1, num_layer, num_patty);
        return ans;
    } else {
        ans += num_patty[n];
        return ans;
    }
}

int main() {
    int N; long long X;
    cin >> N >> X;

    vector<long long> num_layer(N + 1), num_patty(N + 1);
    num_layer[0] = 1; num_patty[0] = 1;
    for (int i = 1; i <= N; i++) {
        num_layer[i] = 2*num_layer[i - 1] + 3;
        num_patty[i] = 2*num_patty[i - 1] + 1;
    }
    
    cout << search_patty(0, N, X, num_layer, num_patty) << endl;
    return 0;
}