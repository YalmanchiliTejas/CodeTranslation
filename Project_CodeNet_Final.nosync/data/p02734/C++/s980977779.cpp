#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <climits>
#include <map>
#include <unordered_map>
#include <cmath>
#include <set>
#include <iterator>
#include <deque>
#include <assert.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull min(ull x, ull y){ if (x<y) return x; return y;}
ull max(ull x, ull y){ if (x<y) return y; return x;}
ll min(ll x, ll y){ if (x<y) return x; return y;}
ll max(ll x, ll y){ if (x<y) return y; return x;}
double min(double x, double y){ if (x<y) return x; return y;}
double max(double x, double y){ if (x<y) return y; return x;}
ull gcd(ull x, ull y){
    if (!x) return y;
    if (!y) return x;
    if (x>y) swap(x,y);
    return gcd(x, y%x);
}
ull inv(ull a, ull c){ // a,c are coprime and a<c
    if (a==1){
        return 1;
    }
    return ((c-(c/a))*inv(c%a,c))%c;
}


ll n, s, a[3005] = {0}, dp[3005][3005] = {0}, ans = 0, m = 998244353;


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>s;

    for (int i = 1; i <= n; i++){
        cin>>a[i];
    }

    for (int i = 0; i <= n; i++){
        dp[i][0]++;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= s; j++){
            dp[i][j] = dp[i-1][j];
            if (a[i]<=j){
                if (a[i]==j) dp[i][j] = (dp[i][j] + (ll)i)%m;
                else dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]])%m;
            }
        }
        ans = (ans + ((dp[i][s] - dp[i-1][s] + m)*(n-i+1))%m)%m;
    }
    cout<<ans<<"\n";
    return 0;
    
}

