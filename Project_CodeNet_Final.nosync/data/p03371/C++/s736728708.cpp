#include <bits/stdc++.h>

#define _rep4(i,p,n,k) for(int i=(p),_rep##_bound=(n),_rep##_inc=(k);i<_rep##_bound;i+=_rep##_inc)
#define _rep3(i,p,n,_a) _rep4(i,p,n,1)
#define _rep2(i,n,_a,_b) _rep4(i,0,n,1)
#define _repcall(a,b,c,d,name,...) name(a,b,c,d)
#define rep(...) _repcall(__VA_ARGS__,_rep4,_rep3,_rep2)

int work(std::istream &in) {
    int A, B, C, X, Y;
    in >> A >> B >> C >> X >> Y;
    int ret = INT_MAX;
    rep(c, std::max(X, Y) + 1) {
        int a = X - c;
        int b = Y - c;
        a = std::max(0, a);
        b = std::max(0, b);
        int cost = a * A + b * B + 2 * c * C;
        ret = std::min(ret, cost);
    }
    return ret;
}

int runTest() {
    int ret = 0;

    struct testcase {
        const char *input;
        int expected;
    };

    struct testcase testdata[] = {
        { "1500 2000 1600 3 2", 7900 },
        { "1500 2000 1900 3 2", 8500 },
        { "1500 2000 500 90000 100000", 100000000 },
    };

    for (const auto &t : testdata) {
        auto in = std::stringstream(t.input);
        int actual = work(in);
        if (actual != t.expected) {
            fprintf(stderr, "expected %d, but actual %d\n", t.expected, actual);
            ret = 1;
        }
    }

    return ret;
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp("--test", argv[1]) == 0) {
        return runTest();
    }
    printf("%d\n", work(std::cin));
    return 0;
}
