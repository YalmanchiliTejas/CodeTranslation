#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
ll a[55],p[55];

ll count(int i, ll j){
    if(i == 0) return 1;
    ll res = -1;
    if(j == 1) res = 0;
    if(j > 1 && j <= a[i-1] + 1) res = count(i-1,  j-1);
    if(j == a[i-1] + 2) res = p[i-1] + 1;
    if(j > a[i-1] + 2 && j <= 2*a[i-1] + 2) res = p[i-1] + 1 + count(i-1, j-a[i-1]-2);
    if(j == 2*a[i-1] + 3) res = 2*p[i-1] + 1;
    return res;
}
int main(){
    int n; ll x; cin >> n >> x;
    a[0] = 1; p[0] = 1;
    rep(i,n){
        a[i+1] = 2*a[i] + 3;
        p[i+1] = 2*p[i] + 1;
    }

    cout << count(n, x) << endl;
}