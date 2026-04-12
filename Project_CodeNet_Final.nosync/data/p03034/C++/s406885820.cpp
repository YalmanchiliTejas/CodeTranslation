#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}


long long infinite(long long A, long long B, long long N) {
    return __gcd<ll>(A, B) == A - B && N - 1 - B > A;
}


ll sum[30][30][100010];


long long simulate(long long A, long long B, vector<ll> &s) {
    if (infinite(A, B, s.size())) return -1e18;

    ll x = A;
    ll sc = s[A];

    int k = (s.size() - 1 - B) / (A - B);
    assert((s.size() - 1 - B) % (A - B) == 0);

    if (A - B < 20) {
        sc += sum[A - B][0][(k - 1) * (A - B)];
        sc += sum[A - B][A % (A-B)][(k - 1) * (A - B) + A] - sum[A - B][A % (A-B)][A];
    } else {
        for (int i = 0; i <= k - 1; i++) {
            sc += s[i * (A - B)];
        }
        for (int i = 1; i <= k - 1; i++) {
            sc += s[i * (A - B) + A];
        }
    }
    return sc;
}

vector<long long> get_divisors(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(n / i);
            if (i != n / i)ret.push_back(i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}


void solve(long long N, std::vector<long long> S) {
    //N = 100000;
    //S.resize(N, 1);


    for (int d = 1; d < 20; d++) {
        for (int s = 0; s < 20; s++) {
            for (int i = s; i < N; i += d) {
                sum[d][s][i] += S[i];
            }
            for (int i = 1; i < N; i++) {
                sum[d][s][i] += sum[d][s][i - 1];
            }
        }
    }
    //N = 10000;
    //s.resize(N);
    // odd
    long long ans = 0;
    for (int B = 1; B <= N; B++) {
        if (N - 1 - B < 0) continue;
        auto ds = get_divisors(N - 1 - B);
        for (auto d : ds) {
            auto A = d + B;
            auto r = simulate(A, B, S);
            //assert((r == -44444) == infinite(A, B, N));
            //cout << A << " " << B << " " << r << " " << infinite(A, B, N) << endl;
            ans = max(ans, r);
        }
    }
    cout << ans << endl;
    cerr << "[]" << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> s(N - 1 - 0 + 1);
    for (int i = 0; i < N - 1 - 0 + 1; i++) {
        scanf("%lld", &s[i]);
    }
    solve(N, std::move(s));
    return 0;
}
