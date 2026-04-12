#include <bits/stdc++.h>
#define REP(i,n) for (int i=0; i<(n); ++i)
#define REPR(i,n,m) for (int i=(n); i>=(m); --i)
using namespace std;
using LL = long long;
using LD = long double;
using PLL = pair<long long, long long>;
using PLD = pair<long double, long double>;
using VLL = vector<long long>;
using VLD = vector<long double>;
using VPLD = vector<PLD>;

const int INF = numeric_limits<int>::max();

int main() {

    int h, w; cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w));

    vector<int> h_vec;
    vector<int> w_vec;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> v.at(i).at(j);
            if (v.at(i).at(j)=='#') {
                h_vec.push_back(i);
                w_vec.push_back(j);
            }
        }
    }

    sort(h_vec.begin(), h_vec.end());
    h_vec.erase(unique(h_vec.begin(), h_vec.end()), h_vec.end());
    sort(w_vec.begin(), w_vec.end());
    w_vec.erase(unique(w_vec.begin(), w_vec.end()), w_vec.end());

    for (int i=0;i<(int)h_vec.size();i++) {
        for (int j=0;j<(int)w_vec.size();j++) {
            cout << v.at(h_vec[i]).at(w_vec[j]);
        }
        cout << endl;
    }
    
    
    return 0;
}
