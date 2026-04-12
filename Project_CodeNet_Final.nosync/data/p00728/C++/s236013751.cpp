#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    for(;;){
        ll N; cin >> N;

        if(N==0){
            return 0;
        } 

        vector<ll> A(N);
        FOR(i, 0, N){
            cin >> A.at(i);
        }

        sort(ALL(A));
        ll sum = 0;
        ll L = A.size();
        FOR(i, 1, L-1){
            sum += A[i];
        }
        ll mean = sum / (N-2);
        p(mean);
    }
    
    return 0;
}
