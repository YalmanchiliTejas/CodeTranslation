#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end())
#define vdelete(v) (v).erase(unique(all(v)), (v).end())
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF 9223372036854775807

bool kr(bool a, bool b);

int n;
string s;
bool memo[100000];
pair<bool,bool> p[4] = {{true,true}, {true,false}, {false,true}, {false,false}};


signed main() {
    cin >> n >> s;
    rep(k,4) {
        if (kr(p[k].fi, p[k].se)) {
            rep(i,n) {
                if (memo[i]) cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}

bool kr(bool a, bool b) {
    bool rev=true;
    memo[0] = a;
    memo[1] = b;
    rep1(i,n-2) {
        if (memo[i]) {
            if (s[i] == 'o') memo[i+1] = memo[i-1];
            else memo[i+1] = !memo[i-1];
        } else {
            if (s[i] == 'x') memo[i+1] = memo[i-1];
            else memo[i+1] = !memo[i-1];
        }
    }
    if (memo[0]) {
        if (s[0] == 'o' && memo[1] != memo[n-1]) rev = false;
        if (s[0] == 'x' && memo[1] == memo[n-1]) rev = false;
    } else {
        if (s[0] == 'x' && memo[1] != memo[n-1]) rev = false;
        if (s[0] == 'o' && memo[1] == memo[n-1]) rev = false;
    }
    if (memo[n-1]) {
        if (s[n-1] == 'o' && memo[0] != memo[n-2]) rev = false;
        if (s[n-1] == 'x' && memo[0] == memo[n-2]) rev = false;
    } else {
        if (s[n-1] == 'x' && memo[0] != memo[n-2]) rev = false;
        if (s[n-1] == 'o' && memo[0] == memo[n-2]) rev = false;
    }
    return rev;
}