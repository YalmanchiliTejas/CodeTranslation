// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

const int mod = 1000 * 1000 * 1000 + 7;
int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int m = input<int>();
    
    string s = input<string>();

    if (s[0] == 'B')
        for (int i = 0; i != m; ++i)
            s[i] = ('R' + 'B' - s[i]);

    if (std::find(ALL(s), 'B') == s.end()) {
        int ans = 0;
        
        for (int fst = 0; fst != 2; ++fst) {
            pair<int, int> cur_dp = {0, 0};

            if (fst == 0)
                cur_dp.first += 1;
            else
                cur_dp.second += 1;

            for (int i = 0; i != n - 1; ++i) {
                pair<int, int> newdp = {0, 0};
                newdp.first = cur_dp.second;
                newdp.second = add(cur_dp.first, cur_dp.second);

                cur_dp = newdp;
            }

            if (fst == 1)
                ans = add(ans, add(cur_dp.first, cur_dp.second));
            else
                ans = add(ans, cur_dp.second);
        }

        cout << ans << "\n";
        return 0;
    } else {
        vector<int> lens = {1};
        assert(s[0] == 'R');

        for (int i = 1; i != m; ++i)
            if (s[i] == 'R' and s[i - 1] == 'R')
                lens.back() += 1;
            else if (s[i] == 'R')
                lens.push_back(1);

        if (s.back() == 'R')
            lens.pop_back();
        
        int limit = 1000 * 1000 * 1000 + 1;
        
        for (int len: {lens[0]})
            if (len % 2 == 0)
                limit = min(limit, len + 1);
            else
                limit = min(limit, len);

        for (int i = 1; i != SZ(lens); ++i)
            if (lens[i] % 2 == 1)
                limit = min(limit, lens[i]);
        
        // dp[k]: start with 0, end with zero, length k.
        vector<int> dp(n + 5);
        vector<int> dp_sum(n + 5);

        dp[0] = 0;
        dp[1] = 1;

        dp_sum[0] = 0;
        dp_sum[1] = 1;
        for (int p = 2; p < SZ(dp); ++p) {
            // for (int last = 1; last <= limit and last + 1 <= p; last += 2)
            //     dp[p] = add(dp[p], dp[p - 1 - last]);

            int upto = min(limit, p - 1);
            if (upto % 2 == 0)
                --upto;

            dp[p] = dp_sum[p - 2];

            if (p - upto - 3 >= 0)
                dp[p] = sub(dp[p], dp_sum[p - upto - 3]);

            dp_sum[p] = add(dp_sum[p - 2], dp[p]);
        }

        int ans = 0;
        for (int beg = 1; beg <= n - 1 and beg <= limit; beg += 2)
            ans = add(ans, mult(beg + 1, dp[n - beg]));

        cout << ans << "\n";

        if (0) {
            auto N = n;
            auto lim = limit;
            int cnt = 0;
            
            for (int mask = 0; mask != (1 << N); ++mask) {
                if (mask == 0 or mask + 1 == (1 << N))
                    continue;
        
                vector<char> s(N);
                for (int i = 0; i != N; ++i)
                    s[i] = bool((mask & (1 << i)) != 0);

                int p = 0;
                while (s[p] != 0 or s[(p + 1) % N] != 1)
                    ++p;

                std::rotate(s.begin(), s.begin() + p, s.end());
                vector<int> lens;
                for (int i = 1; i != N; ++i)
                    if (s[i] == 1 and s[i - 1] == 0)
                        lens.push_back(1);
                    else if (s[i] == 1)
                        lens.back() += 1;

                bool fail = false;
                for (int i = 0; i != N; ++i)
                    if (s[i] == 0 and s[(i + 1) % N] == 0)
                        fail = 1;
                
                if (fail)
                    continue;

                if (*std::max_element(ALL(lens)) > lim)
                    fail = true;

                for (auto elem: lens)
                    if (elem % 2 == 0)
                        fail = true;

                if (fail)
                    continue;

                // for (int i = 0; i != N; ++i)
                //     cout << ((mask & (1 << i)) != 0 ? '1' : '0');

                // cout << "\n";
                cnt += 1;
            }

            assert(ans == cnt);
        }
    }
    
    return 0;
}
