#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

int n;
pll x[200100];

ll mn[200200];
ll mx[200200];
ll mn1[200200];

int main(){
    cin>>n;
    for(int i=0 ; i<n ;i ++){
        scanf("%lld%lld",&x[i].fr,&x[i].sc);
        if(x[i].fr < x[i].sc)
            swap(x[i].fr,x[i].sc);
    }
    sort(x,x+n);
    reverse(x,x+n);
    mn[0] = x[0].sc;
    mx[0] = x[0].sc;
    for(int i=1;i <n ;i ++){
        mn[i] = min(mn[i-1],x[i].sc);
        mx[i] = max(mx[i-1],x[i].sc);
    }
    mn1[n-1] = x[n-1].sc;
    for(int i=n-2; i>=0 ; i--){
        mn1[i] = min(mn1[i+1],x[i].sc);
    }
    mn[n] = 1e18;
    ll r= (x[n-1].fr-x[0].fr)*(mn[n-1]-mx[n-1]);
    for(int i=1 ; i<n ;i ++){
        ll rmx2 = max(mx[i-1],x[i].fr);
        ll rmn2 = min(mn[i-1],mn1[i+1]);
        rmn2 = min(rmn2,x[i].fr);
        ll rmx1 = x[0].fr;
        ll rmn1 = min(x[n-1].fr,x[i].sc);
        r = min(r,(rmx2-rmn2)*(rmx1-rmn1));
    }
    for(int i=1 ; i<n ;i ++){
        ll rmx2 = max(mx[i-1],x[i].fr);
        ll rmn2 = min(mn[i-1],x[n-1].fr);
        ll rmx1 = x[0].fr;
        ll rmn1 = min(mn[n-1],x[i].sc);
        r = min(r,(rmx2-rmn2)*(rmx1-rmn1));
    }
    cout<<r<<endl;

    return 0;
}
