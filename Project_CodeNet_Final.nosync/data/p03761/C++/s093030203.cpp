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
string S, T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N;
    vec ans(26,INF), temp(26,0);
    rep(i,N){
        cin>>S;
        rep(j,S.size()) ++temp[S[j] - 'a'];
        rep(j,26) {
            ans[j] = min(ans[j], temp[j]);
            temp[j] = 0;
        }
    }
    rep(i,26){
        rep(j, ans[i]) cout<<char(i + 97);
    }
    cout<<endl;
}