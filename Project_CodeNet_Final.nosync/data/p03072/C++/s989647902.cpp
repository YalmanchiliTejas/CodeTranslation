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

ll N,M,H,W,K,A,B;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main() {
    cin>>N;
    vec h(N);
    rep(i,N) cin>>h.at(i);
    ll ans = 0;
    bool cansee;
    rep(i,N){
        cansee = true;
        rep(j,i){
            if(h.at(j)>h.at(i)){
                cansee = false;
                break;
            }
        }
        if(cansee) ++ans;
    }
    cout<<ans<<endl;
}