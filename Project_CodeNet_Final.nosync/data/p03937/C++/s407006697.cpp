#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;

int main(){
    int h, w; cin >> h >> w;
    int cnt = 0;
    rep(i, h)rep(j, w) {
        char g; cin >> g;
        if(g == '#') cnt++;
    }

    cout << ((cnt == h+w-1)?"Possible":"Impossible") << endl;

    return 0;
}