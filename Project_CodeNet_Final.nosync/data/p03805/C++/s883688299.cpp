#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

bool d[8][8];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    vector<int> o(n);
    for (int i = 0; i < n; ++i) o[i] = i;
    int ans = 0;
    do{
        if(o[0] != 0) break;
        bool ok = 1;
        for (int i = 0; i < n-1; ++i) {
            if(!d[o[i]][o[i+1]]) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(o.begin(),o.end()));
    cout << ans << endl;
    return 0;
}