#include <bits/stdc++.h>

using namespace std;

int main () {

    int N;
    cin >> N;
    vector<int> heights(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    // reverse(heights.begin(), heights.end());
    int m = 0;
    for (size_t i = 0; i < heights.size(); i++) {
    
        if (heights[i] >= m) {
            ans += 1;
        }
        m = max (m, heights[i]);
    }
    cout << ans << '\n';
    return 0;
}
