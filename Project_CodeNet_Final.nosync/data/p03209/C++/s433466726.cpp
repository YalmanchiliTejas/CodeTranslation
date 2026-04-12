#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll rec(ll n, ll x){
    if(n == 0) return 1;
    ll len = (1ll<<(n+1)) - 3;
    ll num = (1ll<<(n)) - 1;
    if(x == 1) return 0;
    else if(x <= len + 1) return rec(n-1,x-1);
    else if(x == len + 2) return num + 1;
    else if(x < (len + 1) * 2) return num + 1 + rec(n-1, x - len -2);
    else return num * 2 + 1;
}
int main(){
    cout << fixed << setprecision(10);
    ll k;
    ll x;
    cin >> k >> x;
    cout << rec(k,x) << endl;
    return 0;
}