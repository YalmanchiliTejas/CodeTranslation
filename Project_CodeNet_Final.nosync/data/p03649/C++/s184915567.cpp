#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
#define fst first
#define snd second
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

int main(){
    ll n; cin >> n;
    vll a(n);
    ll s = 0;
    rep(i, 0, n){
        cin >> a[i];
        s += a[i];
    }
    sort(a.begin(),a.end());
    reverse(all(a));
    ll aans = 0;
    while(a[0] >= n){
    ll g = (n-1)*n;
    ll ans = 0;
    ll b = INF;
    vll ud(n, 0);
    rep(i, 0, n){
        if(a[i] > n-1){
            ll d = a[i] - n + 1; ll h;
            if(d%n == 0){h = d/n;}
            else{h = d/n + 1;}
            ans += h;
            ud[i] = h;
            a[i] -= h*n;
        }else{
            b = i; break;
        }
    }
    rep(i, 0, n){
        if(i < b){
            a[i] += ans - ud[i];
        }else{
            a[i] += ans;
        }
    }
    aans += ans;
    sort(a.begin(),a.end());
    reverse(all(a));
    }
    prtl(aans);
}
