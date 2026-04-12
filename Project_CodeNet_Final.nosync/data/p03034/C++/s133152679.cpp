#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;
template <class T, class U> inline void chmax(T & a, U const & b) { a = max<T>(a, b); }

/**
 * @note O(\sqrt{n})
 * @note about 1.0 sec for 10^5 queries with n < 10^10
 */
struct prepared_primes {
    int size;
    vector<int> sieve;
    vector<int> primes;

    prepared_primes(int size_)
        : size(size_) {

        sieve.resize(size);
        REP3 (p, 2, size) if (sieve[p] == 0) {
            primes.push_back(p);
            for (int k = p; k < size; k += p) {
                if (sieve[k] == 0) {
                    sieve[k] = p;
                }
            }
        }
    }

    vector<int64_t> prime_factorize(int64_t n) {
        assert (1 <= n and n < (int64_t)size * size);
        vector<int64_t> result;

        // trial division for large part
        for (int p : primes) {
            if (n < size or n < (int64_t)p * p) {
                break;
            }
            while (n % p == 0) {
                n /= p;
                result.push_back(p);
            }
        }

        // small part
        if (n == 1) {
            // nop
        } else if (n < size) {
            while (n != 1) {
                result.push_back(sieve[n]);
                n /= sieve[n];
            }
        } else {
            result.push_back(n);
        }

        assert (is_sorted(ALL(result)));
        return result;
    }

    vector<int64_t> list_all_factors(int64_t n) {
        auto p = prime_factorize(n);
        vector<int64_t> d;
        d.push_back(1);
        for (int l = 0; l < p.size(); ) {
            int r = l + 1;
            while (r < p.size() and p[r] == p[l]) ++ r;
            int n = d.size();
            REP (k1, r - l) {
                REP (k2, n) {
                    d.push_back(d[d.size() - n] * p[l]);
                }
            }
            l = r;
        }
        return d;
    }
};


int64_t solve(int n, const vector<int64_t> & s) {
    int sqrt_n = sqrt(n) + 3;

    vector<vector<vector<int64_t> > > sum(sqrt_n);
    REP3 (delta, 1, sqrt_n) {
        sum[delta].resize(delta, vector<int64_t>(1));
        REP (i, n) {
            int offset = i % delta;
            sum[delta][offset].push_back(sum[delta][offset].back() + s[i]);
        }
    }
    auto calc_small = [&](int a, int b) -> int64_t {
        assert (a - b < sqrt_n);
        int k = (n - 1 - a) / (a - b);
        if (a % (a - b) == 0 and a / (a - b) <= k) return 0;
        int64_t fst = sum[a - b][a % (a - b)].back() - sum[a - b][a % (a - b)][a / (a - b)];
        int64_t snd = sum[a - b][0][k + 1];
        return fst + snd;
    };

    vector<int> used(n);
    int current = 0;
    auto calc_large = [&](int a, int b) -> int64_t {
        int x = 0;
        int64_t acc = 0;
        ++ current;
        for (int i = 0; ; ++ i) {
            used[x] = current;
            x = (i % 2 == 0 ? x + a : x - b);
            if (x == n - 1) return acc;
            if (x < 0 or n <= x or used[x] == current) return 0;
            acc += s[x];
        }
    };

    int64_t answer = 0;
    prepared_primes primes(sqrt_n);
    REP3 (a, 1, n - 1) {
        for (int k : primes.list_all_factors(n - 1 - a)) {
            int b = a - (n - 1 - a) / k;
            if (b <= 0 or a - b <= 0) continue;
            assert (k * (a - b) + a == n - 1);  // there are almost 10^6 pairs of (A, B) when N = 10^5
            chmax(answer, a - b < sqrt_n ? calc_small(a, b) : calc_large(a, b));
        }
    }
    return answer;
}

int main() {
    int n; cin >> n;
    vector<int64_t> s(n);
    REP (i, n) {
        cin >> s[i];
    }
    cout << solve(n, s) << endl;
    return 0;
}
