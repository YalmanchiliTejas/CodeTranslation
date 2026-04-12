#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;
const ll MOD=1e9+7;

int n;
ll p[51];
ll b[51];

ll solve(int x,ll y){
    if (y==0){
        return 0;
    }
    if (y==1 && x==0){
        return 1;
    }
    if (y==1){
        return 0;
    }
    else if (y<=b[x-1]+1){
        return solve(x-1,y-1);
    }
    else if (y==b[x-1]+2){
        return p[x-1]+1;
    }
    else if (y<=2*b[x-1]+2){
        return solve(x-1,y-2-b[x-1])+p[x-1]+1;
    }
    else{
        return p[x-1]*2+1;
    }
}

int main() {
    cin>>n;
    ll x;
    cin>>x;
    p[0]=1;
    b[0]=1;
    rep(i,n){
        p[i+1]=2*p[i]+1;
        b[i+1]=2*b[i]+3;
    }
    ll ans=solve(n,x);
    cout<<ans<<endl;
    

    return 0;
}