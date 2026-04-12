#include <bits/stdc++.h>

using namespace std;

using i64 = long long int;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(a) a.begin(), a.end()

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

int main(){
    vector<i64> v(12);
    rep(i, 12) cin >> v[i];
    sort(all(v));
    bool flag = true;
    rep(i, 3){
        i64 tmp = v[i * 4];
        rep(j, 4){
            if(tmp != v[i * 4 + j]) flag = false;
        }
    }
    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;
}
