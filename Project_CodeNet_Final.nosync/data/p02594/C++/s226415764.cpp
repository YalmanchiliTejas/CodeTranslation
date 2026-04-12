#include <bits/stdc++.h>
using namespace std;

namespace AC {
#define ll long long
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define PDPLL pair<double, PLL>
#define PLPLL pair<ll, PLL>
#define pb push_back
#define fi first
#define se second
#define ls rt << 1
#define rs rt << 1 | 1

    const ll N = 1e5 + 66;

    ll BUGS = 1;

    inline ll read(){
        ll x = 0;    bool flag = 1;   char ch = getchar();
        while(ch < '0' || ch > '9') { if(ch == '-') flag = 0; ch = getchar(); }
        while(ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + ch - '0'; ch = getchar(); }
        if(flag) return x;  return (~(x - 1));
    }

    inline void read(ll arr[], ll s, ll e) { for(ll i = s; i <= e; ++i) arr[i] = read(); }

    inline void write(ll x){
        if(x < 0) { x = ~(x - 1); putchar('-'); }
        if(x > 9) write(x / 10); putchar(x % 10 + '0');
    }

    inline void print(ll x) { write(x); puts(""); }

    inline void print(ll arr[], ll s, ll e) {
        for(ll i = s; i <= e - 1; ++i) write(arr[i]), putchar(' ');
        write(arr[e]); puts("");
    }

    inline ll max3(ll a, ll b, ll c) { return max(a, max(b, c)); }

    inline ll min3(ll a, ll b, ll c) { return min(a, min(b, c)); }

    inline void debugNum(ll num, string ss) { cout << "BUGS" << BUGS++ << " : " << ss << " : " << num << endl; }

    inline void debugArr(ll arr[], ll s, ll e, string ss) {
        cout << "BUGS" << BUGS++ << " : " << ss << " : " << endl;
        for(ll i = s; i <= e; ++i) cout << "i : " << i << " val : " << arr[i] << endl;
    }

    inline void IO() {
        //ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
        //cout << setiosflags(ios::fixed) << setprecision(1); //保留小数点后1位
        //cout << setprecision(1); //保留1位有效数字
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
}using namespace AC;

int main() {
    //IO();
    ll n = read();
    if(n >= 30) puts("Yes");
    else puts("No");
    return 0;
}

