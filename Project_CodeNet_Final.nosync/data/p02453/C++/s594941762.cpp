#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

int main(){
    ll N;
    cin >> N;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A[i];
    }

    ll Q;
    cin >> Q;

    while(Q--){
        ll a;
        cin >> a;

        ll index = lower_bound(ALL(A), a) - A.begin();
        p(index);
    }

    return 0;
}
