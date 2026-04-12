#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = 3.141592653589793;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REPR(i,a,b) for(ll i=b;i>=a;i--)
#define repr(i,n) REPR(i,0,n)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
#define m_p make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,k;
    char tapu;
    string s;
    cin >> n >> s >> k;
    rep(i,n){
        if(i+1==k) tapu = s[i];
    }
    rep(i,n){
        if(s[i]!=tapu) cout << '*';
        else cout << s[i];
    }
    cout << "\n";
    return 0;
}