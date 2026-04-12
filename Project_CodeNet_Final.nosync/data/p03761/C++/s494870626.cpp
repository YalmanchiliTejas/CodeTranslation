#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <tuple>
 
using namespace std;
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define cina(s, n, a) for(int i = s; i < n; i++) cin >> a[i]
#define couta(n, a) for(int i = 0; i < n; i++) cout << a[i] << ' '
#define copy(s, n, a, b) for(int i = s; i < n; i++) b[i] = a[i]
#define yesno(ok) cout << (ok ? "YES" : "NO")
#define mod(a, b) (b + (a % b)) % b
#define MOD (ll)1e9 + 7
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


void solve(){
    int n;
    cin >> n;
    vector <vi> a(n, vi (26, 0));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            a[i][s[j] - 'a'] += 1;
        }
    }
    for(int i = 0; i < 26; i++){
        int cnt = INT_MAX;
        for(int j = 0; j < n; j++){
            cnt = min(a[j][i], cnt);
        }
        while(cnt--) cout << char(i + 'a');
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q = 1;
    //cin >> q;
    for(int i = 1; i <= q; i++){
        solve();
    }
}
