#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define fi first
#define se second
#define dbg(x) cout << #x"="<< (x) << endl

int main(){
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    ll ans=0;

    if(2*c<a+b){
        ll temp=min(x,y);
        ans+=2*c*temp;
        x-=temp;
        y-=temp;
    }

    if(2*c<a){
        ans+=2*c*x;
        y-=x;
        x=0;
    }
    if(2*c<b&&y>0){
        ans+=2*c*y;
        x-=y;
        y=0;
    }

    if(x>0){
        ans+=a*x;
    }

    if(y>0){
        ans+=b*y;
    }

    cout<<ans<<endl;
}