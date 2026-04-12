#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream& operator >> (istream& istr, vector<T>& v){
    for(T& x: v) istr >> x;
    return istr;
}

template<typename T, typename U>
istream& operator >> (istream& istr, pair<T,U>& p){
    istr >> p.first >> p.second;
    return istr;
}

template<typename T>
ostream& operator << (ostream& ostr, vector<T>& v){
    if(!v.empty()){
        ostr << v.front();
        for(auto itr = ++v.begin(); itr != v.end(); itr++)
            // ostr << *itr;
            ostr << " " << *itr;
    }
    return ostr;
}

template<typename T, typename U>
ostream& operator << (ostream& ostr, pair<T,U>& p){
    // ostr << p.first << p.second;
    // ostr << p.first << ", " << p.second;
    ostr << "(" << p.first << ", " << p.second << ")";
    return ostr;
}

template<typename T>
ostream& operator << (ostream& ostr, vector<vector<T>>& vv){
    if(!vv.empty()){
        ostr << vv.front();
        for(auto itr = ++vv.begin(); itr != vv.end(); itr++)
            ostr << endl << *itr;
    }
    return ostr;
}

template<typename T, typename U>
ostream& operator << (ostream& ostr, vector<pair<T,U>>& vp){
    if(!vp.empty()){
        ostr << vp.front();
        for(auto itr = ++vp.begin(); itr != vp.end(); itr++)
            ostr << endl << *itr;
    }
    return ostr;
}

typedef long long ll;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<double> vd;
// vll v(n); v[i]=x;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef vector<vd> vvd;
// vvll v(m,vll(n)); v[i][j]=x;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<pll> vpll;
typedef vector<pd> vpd;
// vpll v(n); v[i]=make_pair(x,y); v[i].first/second;
// v.front() : v[0]
// v.back()  : v[v.size()-1]

#define PI 3.1415926535897932
#define EPS 1e-12
#define INF ((ll)1e+12)
#define REP(i,n) for(ll i=0; i<(n); i++)
#define RREP(i,n) for(ll i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(ll i=(a); i<=(b); i++)
#define FORR(i,a,b) for(ll i=(b); i>=(a); i--)
#define fix(x) cout << fixed << setprecision(x)
#define dump(x) cout << #x << " = " << (x) << endl
#define all(x) (x).begin(),(x).end()

template<typename T> T sum(vector<T>& v){return accumulate(all(v), (T)0);}
template<typename T> inline void sort(vector<T>& v){sort(all(v));}
template<typename T> inline void rsort(vector<T>& v){sort(all(v), greater<T>());}
template<typename T> inline void chmin(T& a, T b){if(a>b) a=b;}
template<typename T> inline void chmax(T& a, T b){if(a<b) a=b;}

int main(){
    ll n, j=1;
    cin >> n;
    vll a(n);
    cin >> a;

    vector<map<ll,ll>> dp(n+1);
    dp[1][1] = a[0];
    dp[2][1] = max(a[0], a[1]);

    FOR(i,3,n){
        j = i/2;
        if(i%2==0){
            dp[i][j-1] = max(dp[i-1][j-1], dp[i-2][j-2]+a[i-1]);
            dp[i][j  ] = max(dp[i-1][j  ], dp[i-2][j-1]+a[i-1]);
        }
        else{
            dp[i][j  ] = max(dp[i-1][j  ], dp[i-2][j-1]+a[i-1]);
            dp[i][j+1] = dp[i-2][j  ]+a[i-1];

        }
    }

    cout << dp[n][j] << endl;
    return 0;
}
