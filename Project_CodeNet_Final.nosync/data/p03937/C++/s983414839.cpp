#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin>>h>>w;
    string s;
    char C[10][10];
    rep(i,h){
        cin>>s;
        rep(j,w){
            C[i][j]=s[j];
        }
    }

    ans=1;

    rep(i,h){
        rep(j,w){
            rep(k,h){
                rep(l,w){
                    if(C[i][j]=='#'&&C[k][l]=='#'&&i<k&&j>l)ans=0;
                }
            }
        }
    }

    if(ans)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
