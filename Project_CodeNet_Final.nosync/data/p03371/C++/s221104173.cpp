#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )

ull ptn[10];
ull A, B, C, X, Y;
int main() {
    cin >> A >> B >> C >> X >> Y;

    // C highest
    if ((A <= C) && (B <= C)) {
        cout << A * X + B * Y << endl;
        return 0;
    }

    ull sum = 0;
    ull m = A < B ? A : B;
    ull mn = 0;
    ull ln = 0;
    if (m == A) {
        mn = X;
        ln = Y;
    } else {
        mn = Y;
        ln = X;
    }
    ull l = A >= B ? A : B;

    // C lowest
    if ((C <= A) && (C <= B)) {
        if (ln >= mn) {
            sum += C * mn * 2;
            ull ac = (ln - mn) * l;
            ull bc = (ln - mn) * 2 * C;
            sum += ac < bc ? ac : bc;
            cout << sum << endl;
            return 0;
        }else{
            sum += C * ln * 2;
            ull ac = (mn - ln) * m;
            ull bc = (mn - ln) * 2 * C;
            sum += ac < bc ? ac : bc;
            cout << sum << endl;
            return 0;
        }
    }
    // C middle

    if ((m + l) <= (C * 2)) {
        ull ac = m * mn + l * ln;
        ull bc = m * mn + 2 * C * ln;
        cout << (ac < bc? ac: bc) << endl;
        return 0;
    }
    if (ln >= mn) {
        sum += C * mn * 2;
        ull ac = (ln - mn) * l;
        ull bc = (ln - mn) * 2 * C;
        sum += ac < bc ? ac : bc;
        cout << sum << endl;
        return 0;
    }else{
        sum += C * ln * 2;
        ull ac = (mn - ln) * m;
        ull bc = (mn - ln) * 2 * C;
        sum += ac < bc ? ac : bc;
        cout << sum << endl;
        return 0;
    }
    cout << "a" << endl;
    cout << "b" << endl;
    cout << "c" << endl;
}