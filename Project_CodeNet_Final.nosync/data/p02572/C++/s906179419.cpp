#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

#define deb(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define END '\n'
#define inf 9e18
#define ff first
#define ss second
#define pb push_back

void solve(){
    int n;
    cin >> n;
    vll A(n);
    cin >> A;
    const ll modu = 1e9 + 7;
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += A[i];
    sum %= modu;
    ll ans = (sum * sum) % modu;
    sum = 0;
    for (int i = 0; i < n; ++i) sum += A[i] * A[i], sum %= modu;
    ans -= sum;
    ans += modu;
    ans %= modu;
    ans *= ((1 + modu) / 2);
    ans %= modu;
    cout << ans << END; 
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}