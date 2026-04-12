#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int M = 1e9+7;
const int N = 1e4;
const int D = 1e2;
int dp[N][D][2];
string s;
int n, d;

int f(int id, int mod, int flag) {
    if (id == n) return mod == 0;
    int &r = dp[id][mod][flag];
    if (r != -1) return r;
    r = 0;
    int lim = flag ? 9 : (s[id]-'0');
    forn(dig, 0, lim+1) {
        int next = (mod + dig) % d;
        bool nw_flag = flag || dig < (s[id]-'0');
        r = (r + f(id+1, next, nw_flag)) % M;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> s >> d;
    n = s.size();
    
    memset(dp, -1, sizeof dp);
    int ans = (f(0, 0, 0) - 1 + M) % M;
    
    cout << ans << endl;
}
