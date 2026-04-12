#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,a,n) for(int i = a; i < n; i++)
#define in(a) cin >> a
#define out(a) cout << a << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

int main() 
{
    int h,w; cin >> h >> w;
    vector<vector<int> > data(h, vector<int>(w));
    vector<int> low(h,0);
    vector<int> col(w,0);

    rep(i,h) {
        string tmp;
        cin >> tmp;
        low[i] = i;
        rep(j,tmp.size()) {
            col[j] = j;
            if(tmp[j] == '#') { data[i][j] = 1; };
        }
    }
#if 0
    rep(i,h){ 
        rep(j,w) {
            cout << data[i][j] << ",";
        }
        cout << endl;
    }
#endif
    for(int cnt = 0; cnt < 100; cnt++) { 
        rep(i,low.size()) {

            int low_check = 0;
            rep(j,col.size()) {
                if(data[low[i]][col[j]]) { low_check++; }
            }    
            if(low_check == 0) { low.erase(low.begin()+i); }
        }

        rep(j,col.size()) {

            int col_check = 0;
            rep(i,low.size()) {
                if(data[low[i]][col[j]]) { col_check++; }
            }    
            if(col_check == 0) { col.erase(col.begin()+j); }
        }
    }
    rep(i,low.size()){ 
        rep(j,col.size()) {
            if(data[low[i]][col[j]]) { cout << '#'; }
            else                     { cout << '.'; }
        }
        cout << endl;
    }
    return 0;
}

