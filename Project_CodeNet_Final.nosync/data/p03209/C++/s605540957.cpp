
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T& a,T b){
    if (a > b) {
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a,T b){
    if(a < b) {
        a=b;
        return true;
    }
    return false;
}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define INF 999999999

    /*Solve*/
ll a[100010];
ll p[100010];

ll rec(ll n,ll x){
    if(x == 1){
        if(n == 0)return 1;
        return 0;
    }
    if(1 < x && x<= a[n-1]+1)return rec(n-1,x-1);
    if(a[n-1]+2 == x)return p[n-1]+1;
    if(a[n-1]+2 < x && x <= 2*a[n-1]+2)return p[n-1]+1+rec(n-1,x-2-a[n-1]);
    if(2*a[n-1]+3 == x)return 2*p[n-1]+1;
    return -1;
}

int main(){
    ll n,x;
    cin >> n >> x;
    a[0]=1;
    p[0]=1;
    for(int i=1;i<=n+1;i++){
        a[i]=2*a[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
    
    ll ans = rec(n,x);
    cout << ans << endl;
}