#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<utility>
#include<map>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,m,n) for(ll i=m;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)
#define FORR(i,n,m) for(ll i=n-1;i>=m;i--)
#define all(in) in.begin(),in.end()
#define ALL(in,K) in,in+K



int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll MIN = min(x,y);
    ll MAX = max(x,y);
    ll min_num = min(a,b);
    ll max_num = max(a,b);
    ll num;
    if(a>c&&b>c){
        num = ((max_num-c)+(min_num-c))*MIN;
    }else{
        num = ((max_num-c)-(c-min_num))*MIN;
    }
    ll ans = a*x+b*y;
    ans = min(ans,ans-num);
    cout << min(ans,MAX*c*2) << endl;
}
