#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) 0
#endif // LOCAL

vector<long long> as(1, 1);
vector<long long> ps(1, 1);

long long solve(long long level, long long x){
    if (level == 0) {
        return x;
    } else if (x >= as[level]) {
        return ps[level];
    } else {
        if (x <= 1) {
            return 0;
        } else if (x <= as[level - 1] + 1) {
            return solve(level - 1, x - 1);
        } else if (x == as[level - 1] + 2) {
            return solve(level - 1, as[level - 1]) + 1;
        } else {
            return solve(level - 1, as[level - 1]) + 1 + solve(level - 1, x - as[level - 1] - 2);
        }
    }
}

int main(){
    long long N, X;

    for (int i = 0; i < 50; i++) {
        as.push_back(as[i] * 2 + 3);
        ps.push_back(ps[i] * 2 + 1);
    }

    cin >> N >> X;

    cout << solve(N, X) << '\n';

    return 0;
}