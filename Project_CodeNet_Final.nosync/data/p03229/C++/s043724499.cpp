#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<deque>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
ll a[100010];

int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N);
    ll ans=0;
    if(N%2==0){
        for(ll i=0;i<N/2-1;i++){
            ans-=a[i]*2;
        }
        ans-=a[N/2-1];
        ans+=a[N/2];
        for(ll i=N/2+1;i<N;i++){
            ans+=a[i]*2;
        }
    }else{
        for(ll i=0;i<N/2-1;i++){
            ans-=2*a[i];
        }
        //-1が２個
        ans-=a[N/2-1]+a[N/2];
        //+2がN/２個
        for(ll i=N/2+1;i<N;i++){
            ans+=2*a[i];
        }

        ll tmp=0;
        //-2がN/2個
        for(ll i=0;i<N/2;i++){
            tmp-=2*a[i];
        }
        //+1が２個
        tmp+=a[N/2]+a[N/2+1];
        //+2がN/2-1
        for(ll i=N/2+2;i<N;i++){
            tmp+=2*a[i];
        }
        ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}