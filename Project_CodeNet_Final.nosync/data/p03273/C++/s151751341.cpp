#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    string ai;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    vector<int> white_c;
    rep(w, W) {
        bool all_white = true;
        rep(h, H) {
            if (A[h][w] == '#') all_white = false;
        }
        if (all_white) white_c.push_back(w);
    }

    for (int i=white_c.size()-1; i>=0; i--) {
        rep(h, H) A[h].erase(white_c[i], 1);
    }

    vector<int> white_r;
    rep(h, H) {
        if (A[h].find("#") == string::npos) white_r.push_back(h);
    }

    rep(h, H) {
        if (find(white_r.begin(), white_r.end(), h) == white_r.end()) cout << A[h] << endl;
    }
    
    return 0;
}

