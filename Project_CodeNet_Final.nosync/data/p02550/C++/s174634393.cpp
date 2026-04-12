#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    ll n,x,y,m,ans = 0,sum = 0,cnt = 0;
    cin >> n >> x >> m;
    y = x;
    vector<bool> f(1e5,false);
    while (!f[x]) {
        f[x] = true;
        (x *= x) %= m;
    }
    for (;n && x != y;n--) {
        ans += y;
        (y *= y) %= m;
    }
    f = vector<bool>(1e5,false);
    while (!f[x]) {
        sum += x;
        cnt++;
        f[x] = true;
        (x *= x) %= m;
    }
    ans += n/cnt*sum;
    n %= cnt;
    for (int i = 0;i < n;++i) {
        ans += x;
        (x *= x) %= m;
    }
    cout << ans << endl;
}