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
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;

int main(){
    ll n,x,M;
    cin>>n>>x>>M;
    vector<int> f(100100,0);
    vector<int> sumation(100100,0);
    ll roop=1;
    ll sum=0;
    vector<ll> memo(0);
    int i=0;
    ll now=x;
    ll syokiti=0;
    ll s=0;
    for(;i<n;i++){
        if(f[now]>0){
            s=f[now];
            roop-=f[now];
            sum-=sumation[now];
            syokiti=sumation[now];
            break;
        }
        f[now]=roop;
        sumation[now]=sum;
        sum+=now;
        syokiti+=now;
        ///
        now=now*now%M;
        roop++;
    }
    if(i==n){
        cout<<sum<<endl;
        return 0;
    }
    //////
    //cout<<"syoki="<<syokiti<<" ,sum="<<sum<<" ,roop="<<roop<<" ,s="<<s<<endl;
    ll ans=syokiti;
    n-=s;
    ans+=(n/roop)*sum;
    for(int i=0;i<=n%roop;i++){
        ans+=now;
        now=now*now%M;
    }
    cout<<ans<<endl;

    
}