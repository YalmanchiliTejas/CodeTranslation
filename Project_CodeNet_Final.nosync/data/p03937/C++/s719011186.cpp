#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int H, W; cin >> H >> W;
    int count = 0;
    vector<string> field(H);
    for (int i = 0; i < H; ++i) {
        cin >> field[i];
    }

    for (int i = 0; i < H; ++i) {
        for (auto j = 0; j < W; ++j){
            if (field[i][j] == '#'){
                ++count;
            }
        }
    }

    if (count == H + W - 1){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
    return 0;
}
