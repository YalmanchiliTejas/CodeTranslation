#include <bits/stdc++.h>
using namespace std;

vector<long long> a(50);

bool is_ok(long long k, int n) {
    for (long long x = k - 51; x <= k + 51; x++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            //if (a.at(i) <= n - 1) continue;
            sum += ((a.at(i) + x - n + 1) + n) / (n + 1);
        }
        if (sum <= x) return true;
        //return sum <= k;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    long long ng = -1;
    long long ok = (long long)(1e16 + 1000) * 50;

    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;

        if (is_ok(mid, n)) ok = mid;
        else ng = mid;
    }
    
    for (long long i = ok - 51; i <= ok + 51; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            //if (a.at(i) <= n - 1) continue;
            sum += ((a.at(j) + i - n + 1) + n) / (n + 1);
        }
        if (sum <= i) {
            cout << i << endl;
            return 0;
        }
    }
}