#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001000
#define mod 1000000007
#define pi 3.1415926535
using namespace std;


int main(void){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(x > y){
        ll ans = c*x*2;
        ans = min(ans,(x-y)*a+min(c*y*2,a*y+b*y));
        cout<<ans<<endl;
    }
    else if(y > x){
        ll ans = c*y*2;
        ans = min(ans,(y-x)*b+min(c*x*2,a*x+b*x));
        cout<<ans<<endl;
    }
    else{
        cout<<min(c*x*2,a*x+b*x)<<endl;
    }
}