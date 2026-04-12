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
 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define cina(s, n, a) for(int i = s; i < n; i++) cin >> a[i]
#define couta(n, a) for(int i = 0; i < n; i++) cout << a[i] << ' '
#define copy(s, n, a, b) for(int i = s; i < n; i++) b[i] = a[i]
#define yesno(ok) cout << (ok ? "Yes" : "No")
#define mod(a, b) (b + (a % b)) % b
#define MOD  (int)1e9 + 7
 
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ll> pll;
typedef std::vector<pii> vpii;
using namespace std;

 
void solve(){
    int n, m;
    cin >> n >> m;
    yesno(m >= n);
}
 
int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q = 1;
    //cin >> q;
    for(int i = 1; i <= q; i++){
        solve();
    }
}
 
