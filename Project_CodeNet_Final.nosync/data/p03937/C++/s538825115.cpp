#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main(){
    int h, w;
    cin >> h >> w;
    int masu_cnt = 0;
    rep(i, h) rep(j, w) {
        char masu;
        cin >> masu;
        if ( masu == '#' ) {
            ++masu_cnt;
        } 
    }
    
    if ( masu_cnt == ( h + w - 1 ) ) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }

    return 0;
}
