#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <numeric>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rept(i,k,n) for(long long i = (k); i < (long long)(n); i++)
#define All(v) v.begin(), v.end()
#define Sort(v) sort(v.begin(),v.end())
#define Rsort(v) sort(v.begin(),v.end(),[](auto a, auto b) { return a > b; })
#define Reverse(v) reverse(v.begin(),v.end())
#define MAX 1000000007
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<long long,long long> Pll;
typedef tuple<int,int,int> Tii;

template <typename T>
ostream& operator<<(ostream& s, const vector<T> &vec){
    for(int i=0;i<vec.size();i++){
        if(i) s << ',';
        else s << '{';
        s <<setw(2)<< vec[i];
    }
    s << '}' << endl;
    return s;
}

int main(){
    ll n,x,m,s=0;
    cin>>n>>x>>m;
    vector<ll> sum(m,0);
    map<ll,ll> mp;
    rep(i,n){
        sum[i+1]=sum[i]+x;
        if(mp.count(x)){
            ll k = mp[x];
            ll c = i-k;
            ll h = (n-k)%c;
            ll ans = sum[k]+(sum[i]-sum[k])*((n-k)/c)+sum[k+h]-sum[k];
            cout<<ans<<endl;
            return 0;
        }
        mp[x]=i;

        x=x*x%m;
        
    }
    cout<<sum[n]<<endl;
    return 0;
}