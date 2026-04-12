#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int H, W;
string field[105];
bool Hvalid[105];
bool Wvalid[105];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        cin >> field[h];
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(field[h][w] == '#') {
                Hvalid[h] = true;
                Wvalid[w] = true;
            }
        }
    }
    for(int h = 0; h < H; h++) {
        if(!Hvalid[h]) continue;
        for(int w= 0; w < W; w++) {
            if(Wvalid[w]) cout << field[h][w];
        }
        cout << endl;
    }
    return 0;
}
