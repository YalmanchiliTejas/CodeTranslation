#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<numeric>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    ll n,x,m; cin >> n >> x >> m;
    ll ans = 0;
    ll now = x;
    ll cnt = 0;
    ll s;
    vector<bool> used(100001,false);
    rep(i,100010){
        if(used[now]){
            s = now;
            break;
        }
        ans += now;
        used[now] = true;
        now = now*now%m;
        cnt++;
    }
    if(n <= cnt){
        ans = 0;
        ll now2 = x;
        rep(i,n){
            ans += now2;
            now2 = now2*now2%m;
        }
        cout << ans << endl;
        return 0;
    }
    ll cnt2 = 0;
    ll now2 = x;
    ll sum = ans;
    rep(i,100010){
        if(now2 == s) break;
        sum -= now2;
        now2 = now2*now2%m;
        cnt2++;
    }
    ans -= sum;
    ans += sum*((n-cnt2)/(cnt-cnt2));
    n -= cnt2+(cnt-cnt2)*((n-cnt2)/(cnt-cnt2));
    ll now3 = s;
    rep(i,n){
        ans += now3;
        now3 = now3*now3%m;
    }
    cout << ans << endl;

}

