#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i,H) cin >> A.at(i);
    for (auto i = A.begin(); i != A.end();) {
        if (count(i->begin(), i->end(), '#') == 0) {
            A.erase(i);
        } else i++;
    }
    vector<int> toErase;
    rep(i, W) {
        bool found = false;
        rep(j, A.size()) {
            if (A.at(j).at(i) == '#') {
                found = true;
                break;
            }
        }
        if (found) continue;
        toErase.push_back(i);
    }
    rep(j, A.size()) {
        string s;
        rep(i,W) {
            if (find(begin(toErase), end(toErase), i) == end(toErase)) s.push_back(A[j].at(i));
        }
        A[j] = s;
    }
    rep(i,A.size()) {
        cout << A.at(i) << endl;
    }
}