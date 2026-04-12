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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

bool ok(const char& s, const char& t1, const char& t2, const char& t3) {
    if ( (s == 'o' && t1 == 'W') || (s == 'x' && t1 == 'S')) return t2 != t3;
    else return t2 == t3;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<string> init = {"WW", "WS", "SS", "SW"};
    string ans = "-1";

    // oox
    for (auto& t : init ) {
        for (int i=1; i<n-1; i++) {
            if ( (t[i] == 'W' && s[i] == 'o') || (t[i] == 'S' && s[i] == 'x') ) t += (t[i-1]=='W'? 'S' : 'W');
            else if ( (t[i] == 'W' && s[i] == 'x') || (t[i] == 'S' && s[i] == 'o') ) t += t[i-1];
        }
        if (ok(s[n-1], t[n-1], t[0], t[n-2]) && ok(s[0], t[0], t[n-1], t[1])){
            ans = t;
            break;
        }
    }
    cout << ans << endl;
}

/*
 * 6
 * ooxoox
 *
 * W
 *
 * 3
 * ○○×
 * WWS -> ×
 * WSW -> ×
 * SSS -> ×
 * SWW -> ×
 */