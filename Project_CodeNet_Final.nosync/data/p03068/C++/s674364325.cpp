#include <bits/stdc++.h>

using namespace std;

/*  テンプレここから */
typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, start, end) for(int i = start; i < end; ++i)
#define all(x) (x).begin(), (x).end()
#define INF (1e9)
#define INFL (1e18)
#define add_mod(a, b, x) ( (ll)(a) + (ll)(b) ) % (ll)(x)
#define mul_mod(a, b, x) ( ((ll)(a) % (ll)(x)) * ((ll)(b) % (ll)(x)) ) % (ll)(x)
#define out(x) cout << (x) << endl;
#define outyes(bool_val) cout << (bool_val ? "yes" : "no") << endl;
#define outYes(bool_val) cout << (bool_val ? "Yes" : "No") << endl;
#define outYES(bool_val) cout << (bool_val ? "YES" : "NO") << endl;
#define outPossible(bool_val) cout << (bool_val ? "Possible" : "Impossible") << endl;
#define outPOSSIBLE(bool_val) cout << (bool_val ? "POSSIBLE" : "IMPOSSIBLE") << endl;

template<typename A, size_t N, typename T>
void array_fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll sub_mod(ll a, ll b, ll x){
    ll tmp = (a - b) % x;
    if(tmp < 0) tmp += x;
    return tmp;
}
ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
/*  テンプレここまで */

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n;
    string s;
    cin >> s;
    cin >> k;

    char tmp = s[k-1];
    rep(i, n){
        if(s[i] != tmp) cout << "*";
        else cout << s[i];
    }
    cout << endl;
}