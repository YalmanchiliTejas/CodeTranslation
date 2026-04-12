#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i=a; i<n; i++)
#define RREP(i, a, n) for(ll i=n-1; i>=a; i--)
typedef long long ll;
const ll mod =1e9+7;
const ll inf =1e18;
using namespace std;

ll n;
ll a[101010];
ll a1[101010], a2[101010];
ll sum1[101010], sum2[101010];
int main() {
    cin>>n;
    REP(i, 0, n) cin>>a[i];

    sort(a, a+n);

    if(n==2) cout<<a[1]-a[0]<<endl;
    else{
        REP(i, 0, n/2+1){
            a1[2*i]=a[i];
            a2[2*i+1]=a[i];
        }
        ll cnt=0;
        RREP(i, n/2, n){
            a1[2*cnt+1]=a[i];
            a2[2*cnt]=a[i];
            cnt++;
        }

        REP(i, 0, n-1){
            sum1[i+1]=sum1[i]+abs(a1[i]-a1[i+1]);
            sum2[i+1]=sum2[i]+abs(a2[i]-a2[i+1]);
        }

        ll ans=0;
        ans=sum1[n-2]+abs(a1[n-1]-a1[0]);
        ans=max(ans, sum1[n-3]+abs(a1[n-3]-a1[n-1])+abs(a1[n-2]-a1[0]));
        RREP(i, 1, n-2){
            ans=max(ans, abs(sum1[i+1]-sum1[n-1])+abs(a1[i+1]-a1[i-1])+sum1[i-1]+abs(a1[i]-a1[0]));
        }
        ans=max(ans, sum2[n-2]+abs(a2[n-1]-a2[0]));
        ans=max(ans, sum2[n-3]+abs(a2[n-3]-a2[n-1])+abs(a2[n-2]-a2[0]));
        RREP(i, 1, n-2){
            ans=max(ans, abs(sum2[i+1]-sum2[n-1])+abs(a2[i+1]-a2[i-1])+sum2[i-1]+abs(a2[i]-a2[0]));
        }
      
        cout<<ans<<endl;
    }
    return 0;
}