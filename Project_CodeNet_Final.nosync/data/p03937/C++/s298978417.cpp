//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int h, w;
    cin >> h >> w;
    vector<int> maxshape(h,0);
    vector<int> minshape(h,w);
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if(s[j] == '#') {
                minshape[i] = min(minshape[i], j);
                maxshape[i] = max(maxshape[i], j);
            }
        }
    }

    bool ans = true;
    rep(i, h-1) {
        if(minshape[i+1] < maxshape[i]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    return 0;
}
