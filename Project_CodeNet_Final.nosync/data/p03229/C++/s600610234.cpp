#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll N;
vector<ll> A;

void input() {
    cin >> N;
    A.resize(N);
    for (auto &v : A)
        cin >> v;
}


void solve() {
    sort(A.begin(), A.end());
    ll maxC = 0;
    vector<ll> as;
    for (int i = 0; i < 2; i++) {
        ll cc = 0;
        as.resize(0);
        for (ll l = 0, r = N - 1; as.size() < N; ) {
            if (i == 0) {
                if (as.size() % 2 == 0) {
                    as.push_back(A[l++]);
                } else {
                    as.push_back(A[r--]);
                }
            } else {
                if (as.size() % 2 == 0) {
                    as.push_back(A[r--]);
                } else {
                    as.push_back(A[l++]);
                }
            }
        }
        for (ll j = 0; j < N - 1; j++) {
            cc += abs(as[j] - as[j + 1]);
        }
        maxC = max(maxC, cc);
        maxC = max(maxC, cc - abs(as[N - 2] - as[N - 1]) + abs(as.back() - as.front()));
    }
    cout << maxC << endl;
}


int main() {
    input();
    solve();
    
    return 0;
}

