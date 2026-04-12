#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef complex<double> P;

#define pb push_back
#define pf push_front
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ユニークなvectorにする。連続した値を除去して切り出す。
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define ADD(a, b) a = (a + b) % mod
#define MUL(a, b) a = (a * b) % mod
#define int ll
#define INF 100000000

#define POS(x) cout<<((x)?"POSSIBLE":"IMPOSSIBLE")<<endl;
#define Pos(x) cout<<((x)?"Possible":"Impossible")<<endl;
#define YES(x) cout<<((x)?"YES":"NO")<<endl;
#define Yes(x) cout<<((x)?"Yes":"No")<<endl;
#define yes(x) cout<<((x)?"yes":"no")<<endl;

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

signed main() {
    string s;
    cin >> s;

    if(s=="a" || s=="i" || s=="u" || s=="e" || s=="o") cout << "vowel" << endl;
    else cout << "consonant" << endl;
}