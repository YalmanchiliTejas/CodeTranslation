#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define RSORT(x) sort((x).rbegin(), (x).rend())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
#define SP << " " <<
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "-1" <<"\n"; return;}
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  1000000007
using namespace std;
using ll = long long;
using ld = long double;
using P  = pair<ll,ll>;
//--GLOBAL---------------------------------

//--MAIN-----------------------------------
void Main() {
    ll N;
    cin>>N;
    vector<ll> A(N);
    vector<ll> L(N);
    vector<ll> R(N);
    rep(i,N){
        L[i]=i-1;
        R[i]=i+1;
    }
    R[N-1]=-1;
    rep(i,N) cin>>A[i];
    priority_queue<P> Q;
    rep(i,N){
        Q.emplace(A[i],i);
    }
    vector<bool> kesu(N,false);
    ll ans=0;
    rep(i,N/2){
        ll kot,ba;
        while(1){
            kot=Q.top().first;
            ba=Q.top().second;
            Q.pop();
            if(!kesu[ba]) break;
        }
        ans+=A[ba];
        if(L[ba]==-1){
            kesu[ba]=true;
            kesu[R[ba]]=true;
            if(R[R[ba]]!=-1) L[R[R[ba]]]=-1; 
        }
        else if(R[ba]==-1){
            kesu[ba]=true;
            kesu[L[ba]]=true;
            if(L[L[ba]]!=-1) R[L[L[ba]]]=-1;
        }
        else{
            kesu[R[ba]]=true;
            kesu[L[ba]]=true;
            A[ba]=A[L[ba]]+A[R[ba]]-A[ba];
            Q.emplace(A[ba],ba);
            if(R[R[ba]]!=-1) {L[R[R[ba]]]=ba; R[ba]=R[R[ba]];}
            else R[ba]=-1;
            if(L[L[ba]]!=-1) {R[L[L[ba]]]=ba; L[ba]=L[L[ba]];}
            else L[ba]=-1;
        }
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
