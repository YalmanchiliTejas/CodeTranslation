#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;
const ll MOD = 1e9 + 7;



int main(){
    int n;
    string s;
    cin >> n >> s;

    rep(fi, 2){
        rep(se, 2){
            vector<int> v(n, -1);
            //0:sheep, 1:wolf
            v[0] = fi;
            v[1] = se;
            bool ok = true;
            for(int i=1; i<n-1; i++){
                if(v[i] == 0){
                    if(s[i] == 'o') v[i+1] = v[i-1];
                    else v[i+1] = !v[i-1];
                }
                if(v[i] == 1){
                    if(s[i] == 'o') v[i+1] = !v[i-1];
                    else v[i+1] = v[i-1];
                }
            }

            //check
            if(s[0] == 'o'){
                if(v[0] == 0) ok &= (v[1] == v[n-1]);
                else ok &= (v[1] != v[n-1]);
            }
            if(s[0] == 'x'){
                if(v[0] == 0) ok &= (v[1] != v[n-1]);
                else ok &= (v[1] == v[n-1]);
            }
            if(s[n-1] == 'o'){
                if(v[n-1] == 0) ok &= (v[n-2] == v[0]);
                else ok &= (v[n-2] != v[0]);
            }
            if(s[n-1] == 'x'){
                if(v[n-1] == 0) ok &= (v[n-2] != v[0]);
                else ok &= (v[n-2] == v[0]);
            }

            if(ok){
                rep(i, n) cout << (v[i] ? "W" : "S");
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}