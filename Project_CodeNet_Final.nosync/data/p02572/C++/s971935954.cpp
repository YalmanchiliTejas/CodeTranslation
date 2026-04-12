#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cctype>
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;

const int INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define sort_all(v) sort(v.begin(), v.end())
#define fill(a) memset(a, 0, sizeof(a))

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FOR_REV(i, a ,b) for(int i = a; i >= b; i--)
#define REP(i, n) FOR(i, 0, n)


void test() {
    int N;
    cin >> N;
    vll a(N);
    ll sum = 0;
    REP(i, N) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    REP(i, N) {
        sum = sum - a[i];
        ans = ((ans % MOD) + (((a[i] % MOD) * (sum % MOD)) % MOD)) % MOD;
    }
    ans %= MOD;
    cout << ans;
}   
 
int main ()     
{
    // int t;
    // cin >> t;
    // while(t--) 
        test();
}
