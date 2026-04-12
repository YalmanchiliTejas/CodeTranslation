#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

ll dfs(ll N, ll X, vector<ll> &M, vector<ll> &P) {
    ll ans = 0;
    if (X==0) return ans;
    else {
        rep(i,5) {
            //cout << N << " " << X << " " << ans << endl;
            if (i==0) {
                X--;
            }
            else if (i==1) {
                if (X>=M[N-1]) {
                    X -= M[N-1];
                    ans += P[N-1];
                }
                else {
                    ans += dfs(N-1,X,M,P);
                    X = 0;
                }
            }
            else if (i==2) {
                X--;
                ans++;
            }
            else if (i==3) {
                if (X>=M[N-1]) {
                    X -= M[N-1];
                    ans += P[N-1];
                }
                else {
                    ans += dfs(N-1,X,M,P);
                    X = 0;
                }
            }
            else if (i==4) {
                X--;
            }
            if (X==0) break;
        }
        //cout << ans << endl;
        return ans;
    }
}

int main(){
    ll N, X;
    cin >> N >> X;
    vector<ll> M,P;
    M.push_back(1);
    P.push_back(1);
    rep(i,50) {
        M.push_back(M[i]*2+3);
        P.push_back(P[i]*2+1);
    }

    ll ans = dfs(N,X,M,P);
    cout << ans << endl;
}