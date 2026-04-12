// itne me hi thakk gaye?
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
#define ll long long 
#define ull unsigned long long
using ld = long double;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll rk = 256;
const ld PI = 3.141592653589793;
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(x) (x).begin(), (x).end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define print(a) for(auto j:a) {cout<<j<<",";} cout << "\n";
#define endl '\n'
#define whatis(x) cout << "> "<<#x << " ==> " << x << endl;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
// // Printing pair
ostream & operator << (ostream & os, pair <ll, ll> const& x) {
    os << x.first << "," << x.second;
    return os;
}
 
// printing vector
template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}
 
// printing set
template <class T>
ostream & operator << (ostream & os, set <T> const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}
 
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}
 
template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]" ;
}
const int mxn = 3005;

int32_t main(){
    FastIO;
    int n;cin >> n;
    vc <ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vc < vc<ll> > dp(mxn, vc <ll> (mxn));
    // dp[0][n-1] is the range where our answer lies
    for(int l=n-1; l>=0; l--) {
        for(int r=l; r<n; r++) {
            if (l==r) {
                dp[l][r] = a[l];
            }
            else {
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
