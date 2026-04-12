#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}


int main() {
    int n;
    cin >> n;

    ll ans = 0;

    ll a[n];
    rep(i,n){
        cin >> a[i];
    }
    sort(a,a+n);

    srep(i,1,n){
        ll times = (a[i]-a[0])/(n+1);
        a[i] -= n*times;
        ans += times;
        rep(j,n){
            if(j!=i){
                a[j] += times;
            }
        }
    }

    sort(a,a+n);

    ll times = max((ll)0,a[0]-(ll)n);

    rep(i,n){
        a[i] -= times;
        ans += times;
    }

    int flag = 0;

    while(true){
        rep(i,n){
            if(a[i]>=n){
                flag = 1;
                rep(j,n){
                    a[j]++;
                }
                a[i] -= n+1;
                ans++;
            }
        }
        if(flag==0)break;
        flag = 0;
    }



    cout << ans << endl;
    return 0;
}
 
 
