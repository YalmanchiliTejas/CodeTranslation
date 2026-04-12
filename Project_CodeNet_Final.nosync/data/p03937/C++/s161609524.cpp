#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vi V(h), V2(h);
    for (int i = 0; i < h; ++i) {
        int maxi = 0, mini = w+2;
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                maxi = j;
                mini = min(mini, j);
            }
        }
        V[i] = maxi;
        V2[i] = mini;
    }
    for (int i = 0; i < h-1; ++i) {
        if (V[i] > V2[i+1]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
    return 0;
}