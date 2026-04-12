#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int64_t MOD = 1e9 + 7;

void combination(int64_t n, int target_size, /*int64_t v[]*/std::vector<int64_t> v) {
    vector<int> indices(target_size);
    const int seed_size = n;
    int start_index = 0;
    int size = 0;

    int64_t ans = 0;
    while (size >= 0) {
        // for (int i = start_index; i < n; ++i) {
        repb(i, start_index, n) {
            indices[size++] = i;
            if (size == target_size) {
                vector<int64_t> comb(target_size);
                for (int x = 0; x < target_size; ++x) {
                    comb[x] = indices[x];
                }
                // if (callback(comb)) return;
                int n = comb.size();
                int64_t num = 1;
                for (int i=0; i<n; ++i) {
                    // cout << comb[i] << " ";
                    num *= (v[comb[i]]%MOD);
                }
                ans += num;
                // cout << endl;
                break;
            }
        }
        --size;
        if (size < 0) break;
        start_index = indices[size] + 1;
    }
    cout << ans%MOD << endl;
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    // int64_t a[n];
    int64_t sum = 0;
    rep(i, n) {
        cin >> a[i];
        // a[i] %= MOD;
        sum += a[i];
        sum %= MOD;
    }

    int64_t ans = 0;
    rep(i, n-1) {
        sum -= a[i];
        if (sum < 0) sum += MOD;
        ans += a[i]*sum;
        ans %= MOD;
    }
    cout << ans%MOD << endl;
    return 0;
    // combination(n, 2, a);
}
