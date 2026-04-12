#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll n,x;
ll a[60];
ll p[60];

ll f(ll N,ll X){
    if(N==0){
        if(X<=0)return 0;
        else return 1;
    }
    else if(X==1)return 0;
    else if(X<=1+a[N-1])return f(N-1,X-1);
    else if(X==2+a[N-1])return p[N-1]+1;
    else if(X<=a[N]-1)return p[N-1]+1+f(N-1,X-a[N-1]-2);
    else return p[N];
}
int main(){
    cin >> n >> x;
    a[0]=1;p[0]=1;
    rep(i,55){
        a[i+1]=a[i]*2+3;
        p[i+1]=p[i]*2+1;
    }
    cout << f(n,x) << endl;

    
    return 0;
}