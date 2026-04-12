#include <bits/stdc++.h>

#ifdef moskupols
    #define debug(...) fprintf(stderr, __VA_ARGS__)
    #define cdebug(...) cerr << __VA_ARGS__
#else
    #define debug(...) do {} while (false)
    #define cdebug(...) do {} while (false)
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC)

#define hot(x) (x)
#define sweet(value) (value)
#define faceless

#define WHOLE(v) (v).begin(),(v).end()
#define RWHOLE(v) (v).rbegin(),(v).rend()
#define UNIQUE(v) (v).erase(unique(WHOLE(v)),(v).end())

typedef long long i64;
typedef unsigned long long ui64;
typedef long double TReal;

using namespace std;

class TSolver {
public:
    int n;
    vector<int> a;

    explicit TSolver(std::istream& in) {
        in >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
    }

    vector<int> srt;

    void Solve() {
        srt = a;
        sort(WHOLE(srt));
    }

    void PrintAnswer(std::ostream& out) const {
        for (int i = 0; i < n; ++i) {
            out << srt[n / 2 - (a[i] >= srt[n / 2])] << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    {
        auto solver = std::make_shared<TSolver>(std::cin);
        solver->Solve();
        solver->PrintAnswer(std::cout);
    }

    timestamp(end);
    return 0;
}
