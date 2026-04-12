#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl

int main(){
    ll N;
    cin >> N;
    
    FOR(mask, 0, 1LL<<N){
        cout << mask << ":";
        FOR(i, 0, 18){
            if(mask>>i&1){
                cout << ' ' << i;
            }
        }
        cout << endl;
    }

    return 0;
}
