#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
    ll N, M, K;
    cin>>N>>M>>K;
    ll dist = 0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            dist += (M-j-1)*(M-j)/2 % mod;
            dist %= mod;
            dist += (N-i-1)*(N-i)/2%mod*M%mod;
            dist %= mod;
            dist += j*(j+1)/2%mod*(N-i-1)%mod;
            dist %= mod;
            dist += (M-j-1)*(M-j)/2%mod*(N-i-1)%mod;
            dist %= mod;
        }
    }
    ll ue = 1, shita1 = 1, shita2 = 1;
    for(ll i=1;i<=N*M-2;++i){
        ue *= i;
        ue %= mod;
    }
    for(ll i=1;i<=K-2;++i){
        shita1 *= i;
        shita1 %= mod;
    }
    for(ll i=1;i<=N*M-K;++i){
        shita2 *= i;
        shita2 %= mod;
    }
    ll two, tmpshita1, tmpshita2, shita11=1, shita22=1, h;
    h = mod - 2;
    while(h>0){
        two = 1;
        tmpshita1 = shita1;
        tmpshita2 = shita2;
        while(2*two<=h){
            two *= 2;
            tmpshita1 *= tmpshita1;
            tmpshita1 %= mod;
            tmpshita2 *= tmpshita2;
            tmpshita2 %= mod;
        }
        h -= two;
        shita11 *= tmpshita1;
        shita11 %= mod;
        shita22 *= tmpshita2;
        shita22 %= mod;
    }
    cout<<dist*ue%mod*shita11%mod*shita22%mod<<endl;
}

