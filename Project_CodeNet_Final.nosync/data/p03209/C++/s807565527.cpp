#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll N, X;
ll a[52], p[52];
 
ll f(ll n, ll x) {
    if(n == 0) return 1;
    if(x == 1) return 0;
    if(x <= a[n-1] + 1) return f(n-1, x-1);
    if(x == a[n-1] + 2) return 1 + p[n-1];
    if(x < a[n]) return p[n-1] + 1 + f(n-1, x - a[n-1] - 2);
    return p[n];
}
 
int main() {
    cin >> N >> X;
    a[0] = 1; p[0] = 1;
    rep1(i,N+1) {
        a[i] = 3 + 2 * a[i-1];
        p[i] = 1 + 2 * p[i-1];
    }
    cout << f(N, X) << endl;
    return 0;
}