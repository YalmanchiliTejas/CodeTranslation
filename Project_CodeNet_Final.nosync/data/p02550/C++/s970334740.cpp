#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string YES[2] = {"NO", "YES"};
string yes[2] = {"No", "Yes"};

int main(){
    ll n, x, m; cin >> n >> x >> m;
    ll a = x, res=0;
    set<ll> st;
    vector<ll> key;
    map<ll, ll> mp;
    while(st.find(a)==st.end() && key.size()<n){
        st.insert(a);
        mp[a] = key.size();
        key.push_back(a);   res += a;
        a = (a*a)%m;    
    }
    //cout << res << endl;
    //rep(i, key.size()) cout << key[i] << ' ';
    if(0<a && n!=key.size()){
        vector<ll> v;
        ll loop=0;
        FOR(i, mp[a], key.size()){
            v.push_back(key[i]);    loop += key[i];
        }
        
        res += (n-key.size())/v.size()*loop;
        ll left = (n-key.size())%v.size();
        rep(i, left) res += v[i];
    }
    cout << res << endl;
}
