#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i=a; i<n; i++)
#define RREP(i, a, n) for(ll i=n-1; i>=a; i--)
typedef long long ll;
const ll mod =1e9+7;
const ll inf =1e18;
using namespace std;

ll n;
ll a[101010];
ll cof1[101010], cof2[101010]; // coefficient
int main() {
    cin>>n;
    REP(i, 0, n) cin>>a[i];

    sort(a, a+n);

    cof1[0]=-1;
    REP(i, 1, n-1) cof1[i] = 2*(i%2 ? 1 : -1);
    cof1[n-1]=(cof1[n-2]>0 ? -1 : 1);
    sort(cof1, cof1+n);

    cof2[0]=1;
    REP(i, 1, n-1) cof2[i] = 2*(i%2 ? -1 : 1);
    cof2[n-1]=(cof2[n-2]>0 ? -1 : 1);
    sort(cof2, cof2+n);

    ll sum1=0, sum2=0;
    REP(i, 0, n){
        sum1+=cof1[i]*a[i];
        sum2+=cof2[i]*a[i];
    }
    cout<<max(sum1, sum2)<<endl;
    return 0;
}