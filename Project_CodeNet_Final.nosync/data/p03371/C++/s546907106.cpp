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

int main(){
    ll C, X, Y;
    cin>>A>>B>>C>>X>>Y;
    ll ans = 1e+18;
    for(ll i = 0; i <= max(X,Y)*2; i += 2){
        ll temp = C*i;
        temp += max(0LL, X - i/2)*A;
        temp += max(0LL, Y - i/2)*B;
        ans = min(ans, temp);
    }
    cout<<ans<<endl;
}