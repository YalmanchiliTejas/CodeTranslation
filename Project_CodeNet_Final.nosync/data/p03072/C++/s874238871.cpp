/*
    B - Great Ocean View
    https://atcoder.jp/contests/abc124/tasks/abc124_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int Hi[20] = {};
    for (int i = 0; i < n; i++) {
        cin >> Hi[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        bool can_see = true;
        int cur = Hi[i];
        for (int j = 0; j <= i; j++) {
            if (cur < Hi[j])
                can_see = false;
        }

        if (can_see)
            sum++;
    }
    cout << sum << endl;
}