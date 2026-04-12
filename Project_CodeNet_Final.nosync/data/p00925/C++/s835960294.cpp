#include <cassert>
#include <tuple>
#include <utility>
#include <iostream>
using namespace std;

using ll = long long;

string expr;
ll a_ans;

ll calc1() {
    ll ans = expr[0] - '0';
    int idx = 1;
    while (idx < expr.size()) {
        char op = expr[idx];
        ll v = expr[idx+1] - '0';

        if (op == '+') ans += v;
        if (op == '*') ans *= v;

        idx += 2;
    }

    return ans;
}

pair<ll, int> term(int idx) {
    ll ret = expr[idx] - '0';
    idx+=1;

    while (idx < expr.size()) {
        char op = expr[idx];
        if (op == '+') break;
        assert(op == '*');
        ll v = expr[idx+1] - '0';
        ret *= v;

        idx += 2;
    }

    return make_pair(ret, idx);
}

ll calc2() {
    ll ans = 0, val;
    int idx = 0, nidx;
    while (idx < expr.size()) {
        tie(val, nidx) = term(idx);
        ans += val; idx = nidx;
        idx += 1;
    }
    return ans;
}

int main() {
    cin >> expr >> a_ans;
    ll ans1 = calc1(), ans2 = calc2();

    if (ans1 == a_ans && ans2 == a_ans) {
        cout << "U";
    } else if (ans1 == a_ans && ans2 != a_ans) {
        cout << "L";
    } else if (ans1 != a_ans && ans2 == a_ans) {
        cout << "M";
    } else {
        cout << "I";
    }
    cout << endl;

    return 0;
}