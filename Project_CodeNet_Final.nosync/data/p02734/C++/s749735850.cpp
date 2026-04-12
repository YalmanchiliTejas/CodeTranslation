#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>
#include <map>
#include <bitset>
#include <functional>
#include <cmath>

#define INF 10000000000
using namespace std;

const long long MOD = 998244353;

int main() {
    long long n, s;
    cin >> n >> s;
    vector<long long> a(n);
    long long f[3010] = {0};

    for(long long i = 0; i < 3010; i++) f[i] = 0;

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    long long ans = 0;
    for(long long i = 0; i < n; i++){
        for(long long j = s; j >= a[i]; j--){
            f[j] += f[j-a[i]];
            f[j] %= MOD;
        }
        f[a[i]]++;
        f[0]++;
        ans += f[s];
        ans %= MOD;
    }

    cout << ans << endl;
}