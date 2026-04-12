#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

void solve(){
    int H, W;
    cin >> H >> W;
    char c;
    int ans=0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c;
            if (c == '#') {
                ans++;
            }
        }
    }

    if (ans == H+W-1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }


    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}
