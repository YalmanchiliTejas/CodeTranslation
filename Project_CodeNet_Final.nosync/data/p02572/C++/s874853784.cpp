// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_dedges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B);}
#define in_wedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C), v[B].pb(A, C);}
#define in_dwedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C);}
#define endl "\n"

const ll MOD = 1000000007;
const ll INF = 1e18;
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    quickio
    ll n;
    cin >> n;

    ll arr[n + 1];
    repp(i, 1, n) cin >> arr[i];

    vector<ll> post(n + 5, 0);


    rrep(i, n, 1) post[i] = (post[i + 1] + arr[i])%MOD;
    // repp(i, 1,n) cout << post[i] << " "; cout << endl;

    ll res = 0;
    repp(i, 1, n - 1){
        ll b = post[i + 1] % MOD;
        ll a = (arr[i] * b) % MOD;
        res = (res + a) % MOD;
    }

    cout << res;
}

ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}