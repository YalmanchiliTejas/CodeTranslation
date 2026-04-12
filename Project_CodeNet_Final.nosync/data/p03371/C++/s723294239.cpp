#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    vector<int> ans;
    int maxx = max(X, Y), minn = min(X, Y);
    ans.push_back(A * X + B * Y);
    ans.push_back(C * minn * 2 + A * (X - minn) + B * (Y - minn));
    ans.push_back(C * maxx * 2);
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}