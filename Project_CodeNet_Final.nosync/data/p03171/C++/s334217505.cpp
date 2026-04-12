#include<bits/stdc++.h>

#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define fn(a,n) for(ll a=0; a<n; a++)
#define flr(a,l,r) for(ll a=l; a<=r;a++)
#define mp make_pair
#define sorta(a) sort(a.begin(), a.end());
#define sortd(a) sort(a.begin(), a.end(), greater<ll>());
#define sortdp(a) sort(a.begin(), a.end(), greater<pair<ll, ll>>());
#define vec std::vector<ll>
#define vp std::vector<pair<ll, ll>>
#define all(a) a.begin(), a.end()
#define inf (long long)1e18
#define infi (int)1e9
#define endl '\n'
#define ff(a, b) for (ll i = 0; i < a; i++) for (ll j = 0; j < b; j++)
#define pp1(a) cout << a << endl;
#define pp2(a, b) cout << a << " " << b << endl;
#define pp3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pp4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;
#define vvl vector<vector<ll>>
#define vvc std::vector<std::vector<char>>
#define vvi std::vector<std::vector<int>>
#define blb(a, b) lower_bound(all(a), b) - a.begin();
#define bub(a, b) upper_bound(all(a), b) - a.begin();
#define graph(n) vvl g(n + 1, vector<ll>(0));
#define in(a, n) vec a(n); f (n) cin >> a[i];
 
#define MOD 1000000007
#define MODLL 1000000000000000007
 
using namespace std;

void print_width(ll x) {
 
    std::cout << std::fixed;
    std::cout << std::setprecision(x);
}
 
ll power(ll x, ll y, ll p = MOD)
{ 
    ll res = 1;      // Initialize result 
 
    x = x % p;  // Update x if it is more than or  
                // equal to p 
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
 
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p;   
    } 
    return res; 
} 
 
void printArr(ll a[], ll n) {
    f(n)
        cout << a[i] << " ";
    cout << endl;
}
 
void printVector(std::vector<ll> v) {
    f(v.size())
        cout << v[i] << " ";
    cout << endl;
}
 
void printVectorPair(std::vector<pair<ll, ll>> v) {
    f(v.size())
        pp2(v[i].first, v[i].second);
    cout << endl;
}
 
void initialize(ll arr[], ll n) {
    for (ll i = 0; i <= n; i++)
        arr[i] = i;
}
 
ll root(ll arr[], ll i) {
 
    while (arr[i] != i) {
        arr[i] = arr[arr[i]] ; 
        i = arr[i];
    }
    return i;
 
}
 
void Union(ll arr[], ll a, ll b) {
    ll root_a = root(arr, a);
    ll root_b = root(arr, b);
 
    arr[root_a] = root_b;
}

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else return gcd(b, a % b);
}
 
ll power_wm(ll x, ll y)
{ 
    ll res = 1;      // Initialize result 
 
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x); 
 
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x);   
    } 
    return res; 
} 

std::vector<ll> vsum(std::vector<ll> a) {
 
    std::vector<ll> s(a.size());
    s[0] = a[0];
    flr (i, 1, a.size() - 1) {
        s[i] = s[i - 1] + a[i];
    }
    return s;
}

void time() {
    #ifndef ONLINE_JUDGE
    cout << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    #endif
}


ll sti(string s) {

    ll ans = 0;
    ll p = 1;

    for (ll i = s.size() - 1; i >= 0; i--) {
        ans = (ans + ((ll)(s[i] - '0') * p) % MOD) % MOD;
        p = (p * 10) % MOD;
    }
    return ans;

}

ll dp[3001][3001];

ll rec(ll i, ll j, ll n, vec &a) {

    ll len = (n - (j - i + 1));

    if (dp[i][j] != -inf)
        return dp[i][j];

    if (i == j) {

        if (len % 2 == 0) {
            dp[i][j] = a[i];
        }
        else {
            dp[i][j] = -a[i];
        }

    }
    else {

        if (len % 2 == 0) {

            ll s1 = rec(i + 1, j, n, a) + a[i];
            ll s2 = rec(i, j - 1, n, a) + a[j];
            dp[i][j] = max(s1, s2);
        }
        else {
            ll s1 = rec(i + 1, j, n, a) - a[i];
            ll s2 = rec(i, j - 1, n, a) - a[j];
            dp[i][j] = min(s1, s2);
        }
    }

    return dp[i][j];
}

int main() {
 
 
 
    //FastIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 
    // start your code here
    print_width(15);

    ff (3001, 3001)
        dp[i][j] = -inf;

    ll n;
    cin >> n;

    vec a(n);
    f (n)
        cin >> a[i];

    cout << rec(0, n - 1, n, a);

    // time();
    return 0;
}