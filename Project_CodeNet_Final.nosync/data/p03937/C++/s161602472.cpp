#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define PI       3.1415926535897932384626433832795028841971
#define INF      100000000
#define EPS      1e-10
#define MOD      1000000007
using namespace std;
typedef long long ll;

int h, w;
char a[8][8];
bool saw[8][8];

int main(){
    cin >> h >> w;
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    int x = 0, y = 0;
    saw[y][x] = true;
    while(true){
        if(y == h-1 && x == w-1) break;
        if(y != h-1 && a[y+1][x] == '#'){
            y++;
            saw[y][x] = true;
            continue;
        }
        if(x != w-1 && a[y][x+1] == '#'){
            x++;
            saw[y][x] = true;
            continue;
        }
        cout << "Impossible" << endl;
        return 0;
    }
    rep(i,h) rep(j,w){
        if(a[i][j] == '#' && saw[i][j] == false){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}
