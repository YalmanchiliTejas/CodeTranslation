#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int H, W;
string field[1005];

int main() {
    //cout.precision(10);
    cin >> H >> W;
    for(int h = 0; h < H; h++) cin >> field[h];
    vector<ll> plus, minus;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(field[h][w] == '.') continue;
            plus.push_back(h+w);
            minus.push_back(h-w);
        }
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    cout << max(abs(plus[0] - plus.back()), abs(minus[0] - minus.back())) << endl;
    return 0;
}

