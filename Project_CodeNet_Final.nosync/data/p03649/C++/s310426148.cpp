#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
template <class T>
bool maxi(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool mini(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
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
    priority_queue<ll> qu;
    rep(i,N) {
        cin>>A[i];
        qu.emplace(A[i]);
    }
    ll ans=0;
    while(1){
        ll x=qu.top();
        if(x+ans<=N-1) break;
        ll buf=(x+ans-(N-1)+(N-1))/N;
        x-=buf*(N+1);
        ans+=buf;
        qu.pop();
        qu.emplace(x);
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
