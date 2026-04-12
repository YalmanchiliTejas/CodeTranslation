#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);

int main() {

    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){cin>>a[i];}

    sort(a.begin(),a.end());


    if(n%2){
        //sdsds
        ll ans = 0;
        for(int i=n/2+1;i<n;i++){
            ans+=a[i]*2;
        }
        //cout<<ans<<endl;
        ans-=(a[n/2]+a[n/2-1]);

        for(int i=0;i<n/2-1;i++){
            ans-=a[i]*2;
        }
       ll ans2=0;

        //dsdsd
        for(int i=0;i<n/2;i++){
            ans2-=a[i]*2;
        }
        for(int i=n/2;i<n/2+2;i++){
            ans2+=a[i];
        }
        for(int i=n/2+2;i<n;i++){
            ans2+=a[i]*2;
        }
    //    cout<<ans2<<ans<<endl;
        cout<<max(ans,ans2)<<endl;

    }else{
        //dsds
        ll ans=0;
        for(int i=0;i<n/2-1;i++){
            ans-=a[i]*2;
        }
        for(int i=n/2+1;i<n;i++){
            ans+=a[i]*2;
        }
        ans+=a[n/2]-a[n/2-1];
        cout<<ans<<endl;




    }

    return 0;
}
