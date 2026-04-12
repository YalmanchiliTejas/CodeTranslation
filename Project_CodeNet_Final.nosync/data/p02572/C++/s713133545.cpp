#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int n;
    long long sum = 0;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n+1, 0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }
    for(int i=0; i<(n-1); i++)
    {
        long long tmp = a[i] * ((b[n] - b[i+1]) % MOD);
        sum = (sum + tmp) % MOD;
    }

    cout << sum << endl;
    return 0;
}

