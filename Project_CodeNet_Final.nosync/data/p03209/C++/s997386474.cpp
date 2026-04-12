#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
vector<ll> a(1,1);
vector<ll> p(1,1);

ll f(ll n, ll x){
    if(n==0){
        if(x==0){
            return 0;
        }else{
            return 1;
        }
    }
    if(x==1){
        return 0;
    }else if(x<=1+a[n-1]){
        return f(n-1,x-1);
    }else if(x==2+a[n-1]){
        return p[n-1]+1;
    }else{
        return p[n-1]+1+f(n-1,x-a[n-1]-2);
    }
}


int main(){
    ll n,x;
    cin>>n>>x;
    for(ll i=0;i<=n;i++){
        a.push_back(a[i]*2+3);
        p.push_back(p[i]*2+1);
    }
    cout<<f(n,x)<<endl;

}