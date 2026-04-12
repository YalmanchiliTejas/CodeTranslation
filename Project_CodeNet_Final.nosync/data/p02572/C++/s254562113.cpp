#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';
ll const mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    ll sum = 0,ans = 0;
    for (int i = 0;i < n;++i) {
        (ans += sum*a[i]%mod) %= mod;
        (sum += a[i]) %= mod;
    }
    cout << ans << endl;
}