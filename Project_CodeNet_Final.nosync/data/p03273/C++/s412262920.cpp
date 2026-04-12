#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> v;
    vector<int> memo;
    rep(i,H) {
        vector<char> vSub(W);
        bool frag = false;
        rep(j, W) {
            cin >> vSub.at(j);
            if (vSub.at(j) == '#'){
                frag = true;
                memo.push_back(j);
            }
        }
        if (frag) {
            v.push_back(vSub);
        }
    }
    sort(memo.begin(), memo.end());
    vector<int> tmp;
    tmp.push_back(memo.at(0));
    rep(i, memo.size()) {
        if (memo.at(i) != tmp.at(tmp.size() - 1)) {
            tmp.push_back(memo.at(i));
        }
    }
    rep(i, v.size()) {
        rep(j, tmp.size()) {
            cout << v.at(i).at(tmp.at(j));
        }
        cout << endl;
    }
    
}
