#include<bits/stdc++.h>

int main() {
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<long> s(N);
    for(auto& i : s)cin >> i;
    long ans{0};
    for(unsigned long i = 1; i < N; ++i){
        long tmp{0};
        for(unsigned long j = 0, k = N - 1; k > i && (k % i != 0 || j < k); j += i, k -= i)ans = max(ans, tmp += s[j] + s[k]);
    }
    cout << ans << endl;
    return 0;
}