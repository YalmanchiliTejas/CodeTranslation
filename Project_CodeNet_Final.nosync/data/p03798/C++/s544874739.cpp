#include <bits/stdc++.h>
#include <functional>
#include <iomanip>
using namespace std;
	
#define int long long
#define pb push_back
#define ub upper_bound
#define lb upper_bound
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>

using ll = long long;
ll INF = LLONG_MAX / 4 - 100;
ll mod = 1e9 + 7;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;
	
class fact {
public:
	int fmod = 1e9+7;
	vector<int> fac, inv;
	fact (int n, int Mod = 1e9+7) {
		fmod = Mod;
		fac = vector<int>(n,0);
		inv = vector<int>(n,0);
		fac[0] = 1; for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i % fmod;
		for (int i = 0;i < n;i++) inv[i] = fact::POW(fac[i],fmod-2);
	}
	ll nCr(ll n, ll r) {return (fac[n] * inv[r] % fmod) * inv[n-r] % fmod;}
	ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%fmod;}a = a * a%fmod; b >>= 1;}return c;}
};
	
template <class T = ll> T in() {T x; cin >> x; return (x);}
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
void EMP(int x) {cout<<"!!!"<<x<<"!!!"<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return a * b / GCD(a, b);}
ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%mod;}a = a * a%mod; b >>= 1;}return c;}
void PRI(ll n) {bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) {a[i] = 1LL;}for (int i = 2; i < n + 1LL; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}
bool isSqrt(ll a) {return pow(sqrt(a),2) == a ? 1 : 0;}
void YesNo(bool a) {if (a) cout << "Yes"; else cout << "No"; cout << endl;}
void yesno(bool a) {if (a) cout << "yes"; else cout << "no"; cout << endl;}
void YESNO(bool a) {if (a) cout << "YES"; else cout << "NO"; cout << endl;}
double dis(int x1, int x2, int y1, int y2) {
    return sqrt((double)abs(x1-x2)*(double)abs(x1-x2)+(double)abs(y1-y2)*(double)abs(y1-y2));
}

bool solve() {
    int n; cin >> n;
    string S; cin >> S;
    REP (i,2) {
        REP (j,2) {
            vi tmp(n,-1);
            tmp[0] = i, tmp[1] = j;
            //0 hituzi 1 ookami
            FOR (k,1,n-1) {
                if (tmp[k]) {
                    tmp[k+1] = ((S[k]=='o')?tmp[k-1]^1:tmp[k-1]);
                } else {
                    tmp[k+1] = ((S[k]=='x')?tmp[k-1]^1:tmp[k-1]);
                }
            }

            int cand;
            if (tmp[0]) {
                cand = ((S[0]=='o')?tmp[1]^1:tmp[1]);
            } else {
                cand = ((S[0]=='x')?tmp[1]^1:tmp[1]);
            }

            if (cand == tmp[n-1]) {
                int cand2;
                if (tmp[n-1]) {
                    cand2 = ((S[n-1]=='o')?tmp[n-2]^1:tmp[n-2]);
                } else {
                    cand2 = ((S[n-1]=='x')?tmp[n-2]^1:tmp[n-2]);
                }
                if (cand2 != tmp[0]) continue;
                REP (k,n) {
                    cout << (tmp[k]?'W':'S');
                }
                cout << endl; return 0;
            }
        }
    }
    cout << -1 << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}
