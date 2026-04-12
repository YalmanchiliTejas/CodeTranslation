#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll>Q;


int main(void){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll lim = max(x,y);
    ll ans = (ll)INF;
    for(ll i=0;i<=lim;i++){
        ll p1 =2*i*c;
        ll p2 = a*max(x-i,0LL);
        ll p3 = b*max(y-i,0LL);
        ans = min(ans,p1+p2+p3);
    }
    cout<<ans<<endl;
    return 0;
}