#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using ll=long long;  
using pLL = std::pair<ll, ll>;
#define SORT(v) std::sort(v.begin(), v.end())
ll a[51],p[51];
ll f(ll n, ll x){
    if(n==0){
        if(x<=0) return 0;
        else{
            return 1;
        }
    }else if(x<=1+a[n-1]){
        return f(n-1,x-1);
    }else{
        return p[n-1]+1+f(n-1,x-(1+1+a[n-1]));
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll X;

    a[0]=p[0]=1;
    
    cin >> N >> X;
    for(ll i=1;i<=N;++i){
        a[i]=2*a[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
    cout << f(N,X) <<endl;
    return 0;
}