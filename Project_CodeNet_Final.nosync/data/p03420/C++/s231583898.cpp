#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#define fi first
#define se second
#define pb push_back
#define last(s) (s)[(s).size()-1]
#define all(a) (a).begin(),(a).end()
#define elif else if
#define left asdasd
#define next zaza
#define prev azaz
#define cclear cout<<flush;
#define x0 kerker
#define time chas
#define y0 lolik
#define kchay ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define files freopen("little.in", "r", stdin);freopen("little.out", "w", stdout);

using namespace std;

using llong = long long;
using ld = long double;
using itn = int;
using ii = pair<int,int>;\
using ull = unsigned long long;
using pll = pair<llong, llong>;
using psi = pair<string, int>;
using ll = pair<llong, llong>;

const llong over999 = 1e9;
const ld over999ld = 1e18+1;
const llong md = 1e9+7;
const ld eps = 1e-9;
const ld Pi = acos(-1);
const llong nich = 0;
const llong mnogo = 300;

/**/
llong n, k, ans, t[1000010];

int check(llong x){
    int res = 0;
    cout << x << endl;
    for(llong i = 1; i * i <= x; i++){
        if(x % i < k && x % ((x/i) + (x %i>0)) < k)continue;
        // res += (i >= k);
        // res += (x/i >= k);
        // cout << x << " " << i << endl;
        res += (x % i >= k) + (x % ((x/i) + (x %i>0)) >= k);
    }
    return res;
}

int32_t main() {
    kchay;
    
    cin >> n >> k;
    // ans = (n-k)*(n-k+1)/2;
    
    for(int i = k + 1; i <= n; i++){
        for(int j = i; j-i <= n; j += i){
            t[j]--;
            t[j-i+k]++;
        }
    }
    
    for(int i = 1; i <= n; i++){
        t[i] += t[i-1];
        ans += t[i];
    }
    
    cout << ans;
    
    return 0;
}