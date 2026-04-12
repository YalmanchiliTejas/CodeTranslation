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
typedef pair<int,int> P;
 
int main(){
    ll a,b,c;
    ll x,y;
    cin>>a>>b>>c>>x>>y;
    ll n = 2*max(x,y);
    ll ans = (ll)INF;
    for(ll i=0;i<=n;i+=2){
        ll num = c*i;
        ll A = i/2;
        ll B = i/2;
        num+=a*max(x-A,0LL);
        num+=b*max(y-B,0LL);
        ans = min(ans,num);
    }
    cout<<ans<<endl;
}
