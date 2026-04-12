#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define WHATIS(x) cout << #x << " is " << x << endl;
#define ERROR(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x

using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

const ll MODBASE = 1000000007LL;
const int MAXN = 200010;
const int MAXM = 1000010;
const int MAXK = 510;
const int MAXQ = 200010;

int n, a[MAXN], nGroup;
vector<int> b[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    nGroup = 1;
    b[nGroup].emplace_back(a[1]);
    FOR(i,2,n) {
        if (a[i] <= b[nGroup][SZ(b[nGroup])-1]) {
            nGroup++;
            b[nGroup].emplace_back(a[i]);
            continue;
        }
        int dau = 1, cuoi = nGroup;
        while (dau <= cuoi) {
            int mid = (dau + cuoi) >> 1;
            if (b[mid][SZ(b[mid])-1] >= a[i]) dau = mid+1;
            else cuoi = mid-1; 
        }
        b[dau].emplace_back(a[i]);
    }
    cout << nGroup;
    return 0;
}
