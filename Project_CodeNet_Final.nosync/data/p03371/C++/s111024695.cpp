#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, s, t;
    cin >> a >> b >> c >> s >> t;
    int ans1 = a * s + b * t;
    int ans2 = 2*c * max(s, t);
    int ans3;
    if (s < t) ans3 = 2*c * s + b * (t - s);
    else ans3 = 2*c * t + a * (s - t);
    cout << min({ans1, ans2, ans3}) << endl;
    return 0;
}