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
    cin>>H>>W;
    vector<string> a(H);
    rep(i,H) cin>>a[i];
    vector<string> ans(H);
    rep(j,W){
        bool push = false;
        rep(i,H){
            if(a[i][j] == '#'){
                if(!push) rep(k,i) ans[k].push_back(a[k][j]);
                push = true;
            }
            if(push){
                ans[i].push_back(a[i][j]);
            }
        }
    }
    for(ll i = H - 1; i >= 0; --i){
        bool remove = true;
        for(char c : ans[i]){
            if(c == '#') remove = false;
        }
        if(remove) ans.erase(ans.begin() + i);
    }
    for(string str : ans){
        for(char c : str) cout<<c;
        cout<<endl;
    }
}
