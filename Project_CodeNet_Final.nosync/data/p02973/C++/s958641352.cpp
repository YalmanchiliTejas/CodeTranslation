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

ll N,M,H,W,K,A,B,L;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll MOD = (1e+9) + 7;

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    multiset<ll> mset;
    rep(i,N){
        auto ite = mset.lower_bound(a[i]);
        if(ite == mset.begin()){
            mset.insert(a[i]);
        }else{
            --ite;
            mset.erase(ite);
            mset.insert(a[i]);
        }
    }
    cout<<mset.size()<<endl;
}
