#include "bits/stdc++.h"
using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define debug(x) cout << #x << ": " << x << endl
using ll = long long;

#define int ll

//**********

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int ans = 0;
    
    if(k==0) ans = n*n;
    else{
    FOR(i,k+1,n+1){
        ans += int(n/i) * (i-k);
        if (n%i - k + 1 > 0) ans += n%i - k + 1;
    }
    }
    printf("%lld\n",ans);
    
    return 0;
    
}





