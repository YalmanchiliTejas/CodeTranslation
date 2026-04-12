#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    mat memo(2,vec(N,0));
    ll ans = 0, last = -1;
    while(last != 0){
        if(last == -1) last = 0;
        rep(i,N){
            a[i] += last - memo[0][i];
            ll num_choice = a[i] / N;
            a[i] %= N;
            memo[1][i] = num_choice;
            ans += num_choice;
        }
        last = 0;
        rep(i,N) last += memo[1][i];
        swap(memo[0], memo[1]);
    }
    cout<<ans<<endl;
}