#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/segtree>
// using namespace atcoder;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>> &pq) {return (ll)pq.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>, greater<T>> &pq) {return (ll)pq.size(); }
ll sz(string &s) {return (ll)s.size(); } 
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }
bool checkindex(ll i,ll n){ return (i < n && i >= 0); }

int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    
    vector<ll> vec;
    vec.push_back(x);
    ll check[m] = {};
    rep(i,0,m) check[i] = -1;
    check[x] = 0;
    ll cnt = 1;
    while(cnt < n){
        ll temp = vec[sz(vec)-1];
        temp *= temp;
        temp %= m;
        if(temp == 0){
            ll ans = 0;
            rep(i,0,sz(vec)){
                ans += vec[i];
            }
            cout << ans << endl;
            return 0;
        }
        else if(check[temp] == -1){
            check[temp] = cnt;
            vec.push_back(temp);
        }
        else{
            ll temp1 = 0,ans = 0;
            rep(i,0,sz(vec)){
                if(i < check[temp]) ans += vec[i];
                else temp1 += vec[i];
            }
            temp1 *= (n-check[temp])/(sz(vec)-check[temp]);
            ans += temp1;
            temp1 = check[temp];

            rep(i,0,(n-check[temp])%(sz(vec)-check[temp])){
                ans += vec[temp1++];
            }
            cout << ans << endl;
            return 0;
        }
        cnt++;
    }
    ll ans = 0;
    rep(i,0,sz(vec)){
        ans += vec[i];
    }
    cout << ans << endl;

    return 0;
}

