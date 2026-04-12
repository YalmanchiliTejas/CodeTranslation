#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    char A[H][W];
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H-1) rep(j, W-1) {
        if (A[i+1][j] == '#' && A[i][j+1] == '#'){
            cout << "Impossible" << endl;
            return 0;
        }
        if (j - 1 >= 0 && i - 1 >= 0){
            if (A[i][j] == '#' && (A[i][j-1] == '#' && A[i-1][j] == '#')){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;

    return 0;
}
