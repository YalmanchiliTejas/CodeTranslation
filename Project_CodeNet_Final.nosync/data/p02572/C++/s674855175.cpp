#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };
const int LIT = 1000000007;
int n, m;
long long sum = 0;

void solve() {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        sum %= LIT;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        sum -= arr[i];
        if (sum < 0) sum += LIT;
        
        ans += sum * arr[i];
        ans %= LIT;
    }
    cout << ans;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
