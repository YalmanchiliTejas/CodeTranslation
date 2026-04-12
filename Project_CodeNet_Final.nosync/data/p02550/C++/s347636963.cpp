#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//2-dim:vector<vector<Type>> vv(n, vector<Type>(m, d));
//3-dim:vector<vector<vector<Type>>> vvv(n, vector<vector<Type>>(m, vector<Type>(l, d)));

signed main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    ll n,x,m; cin >> n >> x >> m;
    vector<ll> ok(m,-1);
    vector<ll> ans(m,0);
    ll now=x;
    ll cnt=0; //kosuu
    while(ok[now]==-1){
        //cout << now << endl;
        ok[now]=cnt;
        ans[cnt+1]=ans[cnt]+now;
        now=(now*now)%m;
        cnt++;
    }
    if(cnt==n){
        cout << ans[n] << endl;
        return 0;
    }
    if(now==0){
        cout << ans[cnt] << endl;
        return 0;
    }
    if(ok[now]==0){
        ll loop=n/cnt;
        ll re=n-loop*cnt;
        ll out=ans[cnt]*loop;
        out+=ans[re];
        cout << out << endl;
        return 0;
    }
    ll out=ans[ok[now]];
    n-=ok[now];
    
    ll loop=n/(cnt-ok[now]);
    ll re=n-loop*(cnt-ok[now]);
    out+=(ans[cnt]-ans[ok[now]])*loop;
    out+=(ans[ok[now]+re]-ans[ok[now]]);
    //rep(i,cnt+1) cout << ans[i] << " ";
    cout << out << endl;
    
}


