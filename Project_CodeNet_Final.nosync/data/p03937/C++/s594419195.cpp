#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h) rep(j, w) {
        char tmp_c;
        cin >> tmp_c;
        if ( tmp_c == '#' ) {
            ++cnt;
        }
    }
    if ( cnt == h + w -1 ) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}