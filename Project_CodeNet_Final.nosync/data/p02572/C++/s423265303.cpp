#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("template.in", "r", stdin), freopen("template.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    //fileio;
        
    int n;
    cin >> n;
    ll A[n];
    ll totalSum = 0;
    ll answer = 0;
    FOR(i, 0, n) {
        cin >> A[i];
        totalSum += A[i];
    }
    FOR(i, 0, n) {
        ll addend = (A[i] % MOD) * ((totalSum - A[i]) % MOD);
        addend %= MOD;
        answer += addend;
        answer %= MOD;
        totalSum -= A[i];
    }
    answer %= MOD;
    cout << answer << "\n";
    return 0;
}
