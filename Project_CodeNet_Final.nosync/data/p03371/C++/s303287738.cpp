#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <functional>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
#define ullrep(i, a, b) for(ull i = (a); i < (b); ++i )
#define ullrrep(i, a, b) for(ull i = (a); i > (b); --i )
#define ullREP(i, a, b) for(ull i = (a); i <= (b); ++i )
#define ullRREP(i, a, b) for(ull i = (a); i >= (b); --i )

ull V[100001];
int A, B, C, X, Y;
int main() {
    cin >> A >> B >> C >> X >> Y;
    int maxv = std::max(X, Y);
    int minv = std::min(X, Y);
    REP(i, 0, maxv) {
        ull sum = 0;
        if (X > i) sum += (X - i) * A;
        if (Y > i) sum += (Y - i) * B;
        sum += i * 2 * C;
        V[i] = sum;
    }
    cout << *std::min_element(V, V + maxv + 1) << endl;
}