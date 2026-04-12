#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
// #include <bits/stdc++.h>

using namespace std;
typedef long long li;

const li mod = 1e9 + 7;

li pow(li x, li n) {
    if (n == 0) {
        return 1;
    }
    li sq = pow(x, n / 2);
    li ans = sq * sq % mod;
    if (n & 1) {
        ans = ans * x % mod;
    }
    return ans;
}


li inv(li x) {
    return pow(x, mod - 2);
}

struct result {
    li stripe;
    li nonstripe;

    result(li str, li nonstr) {
        stripe = str;
        nonstripe = nonstr;
    }

    li total() {
        return (stripe + nonstripe) % mod;
    }
};

result recur(vector<li> hs) {
    set<li> elements(hs.begin(), hs.end());
    li width = hs.size();

    if (elements.size() == 1) {
        li height = hs.front();
        return result(pow(2, height), (pow(2, width) - 2 + mod) % mod);
    } else {
        li height = *min_element(hs.begin(), hs.end());
        vector<vector<li>> subs;
        vector<li> sub;
        li free = 0;
        for (auto &&h : hs) {
            li newh = h - height;
            if (newh == 0) {
                free += 1;
                if (sub.size() > 0) {
                    subs.push_back(sub);
                    sub = vector<li>();
                }
            } else {
                sub.push_back(newh);
            }
        }
        if (sub.size() > 0) {
            subs.push_back(sub);
        }
        li stripe = pow(2, height);
        li nonstripe = pow(2, free);

        li negnonstripe = 2;

        for (auto &&sub : subs) {
            auto res = recur(sub);
            stripe *= res.stripe;
            stripe %= mod;

            nonstripe *= (res.nonstripe + res.stripe * 2 % mod) % mod;
            nonstripe %= mod;

            negnonstripe *= res.stripe % mod;
            negnonstripe %= mod;
        }

        nonstripe = (nonstripe + mod - negnonstripe) % mod;
        return result(stripe, nonstripe);
    }
}

int main() {
    li n;
    cin >> n;

    vector<li> hs(n);
    for (int i = 0; i < n; ++i) {
        cin >> hs[i];
    }

    cout << recur(hs).total() << endl;
    return 0;
}
