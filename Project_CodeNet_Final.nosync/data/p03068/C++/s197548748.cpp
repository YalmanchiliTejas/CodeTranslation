# include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int N = int(5e5) + 2;
const int LG = 20;
const ll mod = 998244353;
const int INF = 2147483647;
const ll linf = 1e18;
const ld pi = acos(-1);
const ld EPS = 1e-10;

int n, k;
string s;
int main (){
    cin >> n >> s >> k;

    string ans = s;
    for (int i = 0; i < sz(s); ++i)
    {
        if (s[i] != s[k - 1]) ans[i] = '*';
    }

    cout << ans << "\n";

    return 0;
}
