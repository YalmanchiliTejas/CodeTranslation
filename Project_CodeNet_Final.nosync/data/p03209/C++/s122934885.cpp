#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <utility>
#include <set>
#include <numeric>
using namespace std;
using LLI = long long int;

// B P P P B
// B BPPPB P BPPPB B
// B BBPPPBPBPPPBB P BBPPPBPBPPPBB B
// B BBBPPPBPBPPPBBPBBPPPBPBPPPBBB P BBBPPPBPBPPPBBPBBPPPBPBPPPBBB B

// [1]
// (1)[3](1)
// (2)[3](1)[1](1)[3](2)
// (3)[3](1)[1](1)[3](2)[1](2)[3](1)[1](1)[3](3)[1]...


vector<LLI> N(51);
void calc_N() {
    N[0] = 1;
    for (int i=1; i<51; i++) {
        N[i] = N[i-1] * 2 + 3;
    }
}

LLI f(int i, LLI k) {
    if (k == 0 || k == -1) {
        return 0;
    }

    if (k < 0) {
        throw "k < 0";
    }

    
    if (i == 0) {
        if (k != 1) {
            throw "k != 1";
        }
        return 1;
    }

    if (k <= N[i-1] + 1) {
        return f(i-1, k-1);
    } else if (k == N[i-1] + 2) {
        return f(i-1, k-2) + 1;
    } else {
        return f(i-1, N[i-1]) * 2 + 1 - f(i-1, N[i]-k-1);
    }
}

int main(int argc, char *argv[])
{
    int n;
    LLI X;
    cin >> n >> X;

    calc_N();
    LLI p = f(n, X);

    cout << p;

    return 0;
}