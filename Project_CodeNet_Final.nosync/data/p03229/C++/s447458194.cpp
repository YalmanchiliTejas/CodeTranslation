#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    

    if (N % 2) {
        long long ans1 = 0, ans2 = 0;
        int K = N / 2;
        for (int i = 0; i < K-1; i++) {
            ans1 += 2 * a[N - 1 - i];
        }
        ans1 += a[N - 1 - K + 1] + a[N - 1 - K];
        for (int i = 0; i < K; i++) {
            ans1 -= 2*a[i];
        }

        for (int i = 0; i < K; i++) {
            ans2 += 2 * a[N - 1 - i];
        }
        ans2 -= (a[N - 1 - K] + a[N - 1 - K - 1]);
        for (int i = 0; i < K - 1; i++) {
            ans2 -= 2*a[i];
        }
        cout << max(ans1, ans2);
    }
    else {
        long long ans = 0;
        int K = N / 2;
        for (int i = 0; i < K - 1; i++) {
            ans += 2 * (a[N - 1 - i] - a[i]);
        }
        ans += a[K] - a[K - 1];
        cout << ans << endl;
    }
}
