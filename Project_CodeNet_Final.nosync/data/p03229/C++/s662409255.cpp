#include <bits/stdc++.h>
using namespace std;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

using i8  = int8_t;
using u8  = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

using f32 = float;
using f64 = double;

#define FOR(i, start, end) for(i64 i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) for(i64 i = 1; i <= n; ++i)
#define RREP(i, n) for(i64 i = n - 1; i >= 0 ; --i)
#define RREPS(i, n) for(i64 i = n; i >= 1; --i)

#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define pb push_back
#define mp make_pair

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename C>
i64 SIZE(const C& c) { return static_cast<i64>(c.size()); }

template<typename T, size_t N>
i64 SIZE(const T (&)[N]) { return static_cast<i64>(N); }


struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
        if(AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;


int main() {
    i64 N; cin >> N;
    deque<i64> A;
    REP(i, N) {
        i64 a; cin >> a;
        A.emplace_back(a);
    }
    sort(A.begin(), A.end());

    auto solve = [](bool front, deque<i64> A) {
        deque<i64> deq;
        i64 a0;
        if (front) {
            a0 = A.front(); A.pop_front();
        } else {
            a0 = A.back(); A.pop_back();
        }
        deq.push_front(a0);

        i64 i = front;
        while (A.size() >= 2) {
            i64 a1, a2;
            if (i % 2 == 0) {
                a1 = A.front(); A.pop_front();
                a2 = A.front(); A.pop_front();
            } else {
                a1 = A.back(); A.pop_back();
                a2 = A.back(); A.pop_back();
            }

            if (abs(deq.front() - a1) + abs(deq.back() - a2) >= abs(deq.front() - a2) + abs(deq.back() - a1)) {
                deq.push_front(a1);
                deq.push_back(a2);
            } else {
                deq.push_front(a2);
                deq.push_back(a1);
            }
            i++;
        }
        if (A.size() == 1) {
            i64 a = A.front(); A.pop_front();
            if (abs(deq.front() - a) >= abs(deq.back() - a)) {
                deq.push_front(a);
            } else {
                deq.push_back(a);
            }
        }
        return deq;
    };

    deque<i64> deq1 = solve(true, A);
    deque<i64> deq2 = solve(false, A);

    auto sdiff = [](deque<i64> &deq) {
        i64 res = 0;
        i64 prev = -1;
        for (i64 &x : deq) {
            if (prev != -1) res += abs(x - prev);
            prev = x;
        }
        return res;
    };

    if (sdiff(deq1) >= sdiff(deq2)) {
        cout << sdiff(deq1) << endl;
        // for (i64 &x : deq1)  cout << x << " ";
        // cout << endl;
    } else {
        cout << sdiff(deq2) << endl;
        // for (i64 &x : deq2)  cout << x << " ";
        // cout << endl;
    }

    return 0;
}
