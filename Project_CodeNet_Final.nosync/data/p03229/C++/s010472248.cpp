#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

#define rep(i, n) for(int i = 0;i < (int)(n); i++)
#define pb push_back
typedef long long ll;
using namespace std;


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> front;
    vector<ll> back;


    for (int i = 0; i < n / 2 + n % 2; ++i) {
        front.push_back(a[i]);
    }

    for (int i = 0; i < n / 2; ++i) {
        back.push_back(a[n - 1 - i]);
    }

    vector<ll> front2;
    vector<ll> back2;

    for (int i = 0; i < front.size(); ++i) {
        if (i % 2 == 0) {
            front2.insert(front2.begin(), front[i]);
        } else {
            front2.push_back(front[i]);
        }
    }

    for (int i = 0; i < back.size(); ++i) {
        if (i % 2 == 0) {
            back2.push_back(back[i]);
        } else {
            back2.insert(back2.begin(), back[i]);
        }
    }

    vector<ll> rev;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            rev.push_back(front2[i / 2]);
        } else {
            rev.push_back(back2[i / 2]);
        }
    }


    ll ans = 0;
    ll ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            ans += abs(rev[i - 1] - rev[i]);
        }
    }



    vector<ll> ff;
    vector<ll> bb;

    for (int i = 0; i < n / 2; ++i) {
        ff.push_back(a[i]);
    }

    for (int i = 0; i < n / 2 + n % 2; ++i) {
        bb.push_back(a[n - 1 - i]);
    }

    vector<ll> ff2;
    vector<ll> bb2;

    for (int i = 0; i < ff.size(); ++i) {
        if (i % 2 == 0) {
            ff2.insert(ff2.begin(), ff[i]);
        } else {
            ff2.push_back(ff[i]);
        }
    }

    for (int i = 0; i < bb.size(); ++i) {
        if (i % 2 == 0) {
            bb2.push_back(bb[i]);
        } else {
            bb2.insert(bb2.begin(), bb[i]);
        }
    }

    vector<ll> res;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            res.push_back(bb2[i / 2]);
        } else {
            res.push_back(ff2[i / 2]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            ans2 += abs(res[i - 1] - res[i]);
        }
    }
    cout << max(ans, ans2);
    return 0;
}
