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

const int N = 3001;
ll dp[N][N];
int v[N];

ll f(int i, int j) {
    if (i == j) return v[i];
    ll &r = dp[i][j];
    if (r != -1) return r;
    ll a = v[i] - f(i+1, j);
    ll b = v[j] - f(i, j-1);
    return r = max(a, b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    forn(i, 0, n) {
        cin >> v[i];
    }
    
    memset(dp, -1, sizeof dp);
    cout << f(0, n-1) << endl;
}
