#include <bits/stdc++.h>

#define _rep4(i,p,n,m) for(int i=(p),_i##_end=(n),_i##_inc=(m);i<_i##_end;i+=_i##_inc)
#define _rep3(i,p,n,_a) _rep4(i,p,n,1)
#define _rep2(i,n,_a,_b) _rep4(i,0,n,1)
#define _rep_call(a,b,c,d,name,...) name(a,b,c,d)
#define rep(...) _rep_call(__VA_ARGS__,_rep4,_rep3,_rep2)

int work(std::istream &in) {
    int A, B, C, X, Y;
    in >> A >> B >> C >> X >> Y;

    int m = INT_MAX;
    rep(k, std::max(X, Y) + 1) {
        int i = std::max(0, X - k);
        int j = std::max(0, Y - k);
        int cost = i * A + j * B + 2 * k * C;
        m = std::min(m, cost);
    }
    return m;
}

struct testdata {
    const char *input;
    int expected;
};

int test() {
    int ret = 0;

    struct testdata testset[] {
        {"1500 2000 1600 3 2", 7900},
        {"1500 2000 1900 3 2", 8500},
        {"1500 2000 500 90000 100000", 100000000},
    };

    const int TESTLEN = sizeof(testset) / sizeof(testset[0]);
    for (int i = 0; i < TESTLEN; ++i) {
        std::stringstream sin(testset[i].input);
        int actual = work(sin);
        if (actual != testset[i].expected) {
            fprintf(stderr, "ERROR: expected: %d, but actual %d\n", testset[i].expected, actual);
            ret = 1;
        }
    }

    return ret;
}

int main(int argc, char *argv[]) {
    std::cin.tie(nullptr);

    if (argc == 2 && strcmp("--test", argv[1]) == 0) {
        exit(test());
    }
    printf("%d\n", work(std::cin));
}
