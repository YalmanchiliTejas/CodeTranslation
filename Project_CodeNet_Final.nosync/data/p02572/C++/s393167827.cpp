/*ॐ नमो भगवते वासुदेवाय नमः*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pf push_front
#define fori(i, a, n) for(int i = a; i < n; ++i)
#define MAX(x) (*max_element(all(x)))
#define MIN(x) (*min_element(all(x)))
#define sortarr(a, n) sort(a, a + n)
#define sortvec(V) sort(all(V))

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unordered_map<int, int, custom_hash> u_map;
typedef unordered_set<int, int, custom_hash> u_set;
typedef vector<int> V;
typedef pair<int , int> pairi;
typedef set<int> seti;
typedef priority_queue<int> p_queue;
typedef deque<int> deqi;

const int MOD = 1e9+7;
const int INF = 1e9+8;
const double pi = 3.14159265359;

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int inverse(int x){
    return binpow(x, MOD - 2, MOD);
}

void solve()
{
    int n, sum = 0;
    cin >> n;
    V a(n);
    for(auto & i : a)   cin >> i , sum += i;
    int ans = 0;
    for(auto i : a){
        sum -= i;
        int te = (sum % MOD) * i;
        ans += te;
        ans = ans % MOD;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n ";
}