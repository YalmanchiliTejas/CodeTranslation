#include <bits/stdc++.h>
struct Fast {Fast(){std::cin.tie(0);std::ios::sync_with_stdio(false);}} fast;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define repR(i, n) for(ll i = n; i >= 0; i--)
#define For(i, m, n) for(ll i = m; i < n; i++)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) v.begin(), v.end()

using namespace std;

ll mod = 1e9+7;
inline ll gcd(ll a, ll b){
    ll r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

inline ll lcm(ll x, ll y)
{
    if(x == 0 || y == 0) {
        return -1;
    }
    
    return (x * y / gcd(x, y));
}

inline ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

inline ll nCr(ll n, ll r) {
    if ( r * 2 > n ) r = n - r;
    ll dividend = 1;
    ll divisor  = 1;
    for ( ll i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return (dividend / divisor);
}

// 因数分解
inline vector<pair<ll, int>>factorize(ll n){
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i) continue;
        res.emplace_back(i, 0);
        while(n % i == 0){
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}

inline bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

//階乗
inline ll factorialMethod(ll k){
    ll sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

inline ll vector_finder(std::vector<ll> vec, ll number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
    if (index != vec.size()) { // 発見できたとき
        return 1;
        
        
    }
    else { // 発見できなかったとき
        return 0;
    }
}

void recursive_comb(ll *indexes, ll s, ll rest, std::function<void(ll *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++) indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}

int main(){
    string ans = "No";
    string s;
    cin >> s;
    
    rep(i, s.size()-1){
        if(s[i] != s[i+1]){
            ans = "Yes";
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}
