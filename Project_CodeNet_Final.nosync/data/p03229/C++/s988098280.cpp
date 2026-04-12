#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "1" <<"\n"; return;}
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  1000000007
#define PI (acos(-1))
using namespace std;
using ll = long long;
using ld = long double;
using P  = pair<ll,ll>;
//--GLOBAL---------------------------------

//--MAIN-----------------------------------
void Main() {
    ll N; cin>>N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N) cin>>A[i];
    SORT(A);
    ll ans=0;
    if(N%2==0){
        rep(i,N/2-1){
            ans-=A[i]*2;
        }
        ans-=A[N/2-1];
        ans+=A[N/2];
        reps(i,N/2+1,N){
            ans+=A[i]*2;
        }
    }
    else{
        rep(i,N/2-1){
            ans-=A[i]*2;
        }
        reps(i,N/2+2,N){
            ans+=A[i]*2;
        }
        ll ans2=0,ans3=0;
        ans2=-A[N/2-1]-A[N/2]+A[N/2+1]*2;
        ans3=-A[N/2-1]*2+A[N/2]+A[N/2+1];
        ans+=max(ans2,ans3);
    }
    cout<< ans <<"\n";

}
//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------
