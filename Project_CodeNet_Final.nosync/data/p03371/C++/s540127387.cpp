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
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=INF;
    if(x>=y){
        ans=min(ans,x*c*2);
        ans=min(ans,y*c*2+(x-y)*a);
    }else{
        ans=min(ans,y*c*2);
        ans=min(ans,x*c*2+(y-x)*b);
    }
    ans=min(ans,x*a+y*b);
    cout<<ans<<endl;
}