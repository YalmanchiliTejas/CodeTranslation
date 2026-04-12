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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=0;
    ans+=a[n-1]-a[0];
    for(ll i=1;i<n/2;i++){
        //cout<<"i="<<i<<" ";
        ans+=a[n-i]-a[i];
        ans+=a[n-1-i]-a[i-1];
        //cout<<ans<<endl;
    }
    if(n%2==1){
        ans+=max(a[n/2+1]-a[n/2],a[n/2]-a[n/2-1]);
    }
    cout<<ans<<endl;
    
}