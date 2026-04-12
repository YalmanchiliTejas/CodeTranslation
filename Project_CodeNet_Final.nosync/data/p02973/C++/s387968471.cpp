#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define eee(a) (cerr << (#a) << ": " << (a) << endl);


using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using mint = map<int, int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const char sp = ' ';
const char cmm = ',';
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LINF = 1e18;

ll mod(ll a, ll b){return (a%b+b)%b;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void Judge(bool b){b?Yes():No();}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void JUDGE(bool b){b?YES():NO();}
ll powmod(ll b, ll e){ll r=1;while(e>0){if(e&1)r=(r%MOD)*(b%MOD)%MOD;b=(b%MOD)*(b%MOD)%MOD;e>>=1;}return r;}
double distance(ll x1, ll y1, ll x2, ll y2){return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T>
void ppp(T n){cout << n << endl;}
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    int len = v.size();
    s << '[';
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len-1) s << ", ";
    }
    s << ']';
    return s;
}

struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(15);
    };
}fastio;



int main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    multiset<int> m;
    rep(i, n){
        int idx = n-i-1;
        auto it = m.upper_bound(a[idx]);
        if(it != m.end()){
            m.erase(it);
        }
        m.insert(a[idx]);
    }
    ppp(m.size());

    return 0;
}
