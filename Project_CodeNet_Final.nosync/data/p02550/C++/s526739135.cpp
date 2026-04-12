#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    REP(i,v.size()){if(i)os<<" ";os<<v[i];}return os;}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    REP(i,v.size()){if(i)os<<endl;os<<v[i];}return os;}
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
//#define int ll

// const int md = 1000000007;
const int INF = 1<<30;

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> s(m + 1,-1);
    ll prev = x;
    ll nv = 0;
    s[prev] = x;
    bool f = false;
    ll cnt = 0;
    rep(i, n-1)
    {
        nv = (prev * prev) % m;
        cnt++;
        if (s[nv] != -1)
        {
            f = true;
            break;
        }
        s[nv] = nv + s[prev];
        prev = nv;
    }
    if (!f)
    {
        cout << s[prev] << endl;
        return 0;
    }
    ll loop = 0;
    ll ans = s[nv] - nv;
    ll lf = nv;
    prev = nv;
    rep(i, n)
    {
        ll nv = (prev * prev) % m;
        loop++;
        if (nv == lf)
        {
            break;
        }
        prev = nv;
    }

    ll d = cnt - loop;
    ll k = (n - d) % (loop);
    
    ll cum;
    if (loop == 1){
        cum = nv;
    }else{
        cum = s[prev] - s[nv] + nv;
    }
    //cout << loop << endl;
    ans += cum * (((n - d) / loop));
    rep(i,k){
        ll nv = (prev * prev) % m;
        ans += nv;
        prev = nv;
    }
    cout << ans << endl;
}
