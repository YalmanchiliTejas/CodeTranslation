#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}

template <class T>
void read(T &x) {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        ;
    for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
#define ll long long 
#define lll __int128_t
#define pb push_back
#define mp make_pair
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
ll vis[200005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x,i, j, k, l, n, m;
    cin >> n >> x >> m;
    ll cx = x;
    vector<ll> data;
    data.pb(x);
    for (i = 2;i<=1000000;i++){
        cx = (cx * cx) % m;
        data.pb(cx);
    }
    ll sz = data.size();
    ll repst, repl;
    for (i = 1; i <= sz;i++){
        if(vis[data[i-1]]!=0){
            repst = vis[data[i-1]];
            repl = i - vis[data[i-1]];
            break;
        }
        else{
            vis[data[i-1]] = i;
        }
    }
    ll ans = 0;
    for (i = 1; i < repst&&i<=n;i++){
        ans += data[i - 1];
    }
    if(n>=repst){
        ll kola = n - repst + 1;
        ll div = kola / repl;
        ll sum = 0;
        for (i = 1; i <= repl;i++){
            sum += data[i + repst - 2];
        }
        ans += (sum * div);
        ll extra = kola % repl;
        for (i = 1; i <= extra;i++){
            ans+=data[i + repst - 2];
        }
    }
    cout << ans << "\n";
    return 0;
}