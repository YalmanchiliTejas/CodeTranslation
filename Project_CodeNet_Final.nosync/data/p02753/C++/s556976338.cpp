#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define per1(i,n) for(int i=int(n);i>0;i--)
#define foreach(i,n) for(auto &&i:n)
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define GSORT(x) sort(all(x), greater<int>())
#define REV(x) reverse(all(x))
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define LOWitr(x, n) lower_bound(all(x), n)
#define UPRitr(x, n) upper_bound(all(x), n)
#define cii(x) int x;cin >> x
#define cis(x) string x;cin >> x
#define co(x) cout << x << endl
#define dump(x)  cout << #x << " = " << (x) << endl
#define truecheck assert
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef long long int64;
template<class T,class U>bool chmax(T &a, const U &b) { if (a<b) { a=b; return true; } return false; }
template<class T,class U>bool chmin(T &a, const U &b) { if (b<a) { a=b; return true; } return false; }
const int INF = 1e9, MOD = 1e9 + 7;
const LL LLINF = 1e16;

int main() {
    fastcin();
    cout << fixed << setprecision(10);
    VI n = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    cis(s);
    
    auto ans = (s == "AAA" || s == "BBB")?"No":"Yes";

    co(ans);
    return 0;
}