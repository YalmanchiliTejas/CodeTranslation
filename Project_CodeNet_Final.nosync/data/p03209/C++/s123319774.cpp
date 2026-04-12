#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

#ifndef INPUTS_DIR
#define INPUTS_DIR "./"
#endif

using namespace std;

long long len[55];

map<pair<ll, ll>, ll> memo;

long long f(long long level, long long ub) {
    if (ub <= 0) return 0;
    auto key = make_pair(level, ub);
    if (memo.count(key)) return memo[key];
    assert(ub <= len[
            level]);
//    cout << level << " " << ub << endl;
    if (level == 0) {
        return ub == 1;
    }
    if (ub == len[level]) ub--;
    long long secondBegin = len[level] - 1 - len[level - 1];
    ll ans = 0;

    if (secondBegin <= ub) {
        ans += f(level - 1, min(ub - secondBegin, len[level - 1]));
    }
    if (ub >= secondBegin) ans++;
    if (ub >= secondBegin - 1) {
        ans += f(level - 1, min(len[level - 1], ub - 1));
    } else {
        ans += f(level - 1, ub - 1);
    }

    return memo[key] = ans;
}

void solve(ll N, ll X) {
    len[0] = 1;
    for (int i = 1; i < 55; i++) len[i] = len[i - 1] * 2 + 3;
//    cout << f(1, 3) << endl;
//    for (int i = 1; i <= len[2]; i++) {
//        cout << f(2, i) - f(2, i - 1) << " ";
//    }
//    cout << endl;
    cout << f(N, X) << endl;
}


void main_(istream &cin) {
    ll N;
    ll X;
    cin >> N;
    cin >> X;
    solve(N, X);
}

int main() {
#ifdef INTELLIJ
    ifstream ifs(string(INPUTS_DIR) + "in_1.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}



