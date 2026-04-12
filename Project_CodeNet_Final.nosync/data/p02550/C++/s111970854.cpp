#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    int64 n,x,m;
    cin >> n >> x >> m;

    int k = log2(n) + 1;
    vector<int> tb;
    unordered_map<int, int> mp;
    tb.emplace_back(x);
    mp[0] = x;
    int64 s = -1;
    {
        int cnt = 1;
        int64 t = x;
        while(true) {
            t *= t;
            t %= m;
            tb.emplace_back(t);
            if (mp[t]) {
                s = mp[t];
                break;
            }
            mp[t] = cnt;
            cnt++;
        }
    }

//    debug(tb);


    int64 ans = 0;
    for (int i=0; i<s; i++) ans += tb[i];

    int64 t = 0;
    for (int i=s; i<tb.size()-1; i++) t += tb[i];

//    debug(s);
//    debug(tb.size());
    int loop = tb.size() - s - 1;

    if (loop > 0) {
        int64 k = (n-s) / loop;
        t *= k;
        n -= s + k * loop;
        for (int i=s; i<n+s; i++) t += tb[i];
    }

    cout << ans + t << endl;
}
/*
 * 492443244981950
 * 492443256176507
 * 492443256176507
 */