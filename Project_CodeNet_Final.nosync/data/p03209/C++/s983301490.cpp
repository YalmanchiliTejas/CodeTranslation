#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i,x) for(ll i=1;i<=(ll)(x);i++)
#define rrep(i,x) for(ll i=((ll)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=(ll)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007 
using namespace std;
ll a[51];
ll p[51];
ll f(ll n, ll x){
    if(n == 0){
        return x <= 0 ? 0 : 1;
    }else if(x <= 1 + a[n - 1]){
        return f(n-1, x -1);
    }else {
        return p[n-1] + 1 + f (n-1, x-2-a[n-1]);
    }
}

int main() {
    ll n , x;
    cin >> n >> x;
    p[0] = 1;
    a[0] = 1;
    reps(i, n){
        a[i] = a[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }
    cout << f(n, x) << endl;
}
