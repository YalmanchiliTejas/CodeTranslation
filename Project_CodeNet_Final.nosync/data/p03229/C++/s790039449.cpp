
#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> AS = A;
    sort(AS.begin(), AS.end());
    vector<ll> AR = A;
    sort(AR.rbegin(), AR.rend());

    ll ans = 0;
    ll tmp = 0;
    if (N % 2 == 1){

        ll prev = AS[N/2];

        rep(i,N/2){
            tmp += abs(prev- AS[i]);
            tmp += abs(AS[i]-AR[i]);
            prev = AR[i];            
        }
        ans = max(ans, tmp);
        prev = AS[N/2];
        tmp = 0;
        rep(i,N/2){
            tmp += abs(prev-AR[i]);
            tmp += abs(AR[i]-AS[i]);
            prev = AS[i];
        }
        ans = max(ans, tmp);
    }
    else{
        ll prev = AS[N/2];

        rep(i,N/2-1){
            tmp += abs(prev- AS[i]);
            tmp += abs(AS[i]-AR[i]);
            prev = AR[i];            
        }
        tmp += abs(prev-AS[N/2-1]);
        ans = max(ans, tmp);

        prev = AS[N/2];
        tmp = 0;
        rep(i,N/2-1){
            tmp += abs(prev- AR[i]);
            tmp += abs(AR[i]-AS[i]);
            prev = AS[i];            
        }
        tmp += abs(prev-AS[N/2-1]);
        ans = max(ans, tmp);
    }

    cout << ans << endl;

}
