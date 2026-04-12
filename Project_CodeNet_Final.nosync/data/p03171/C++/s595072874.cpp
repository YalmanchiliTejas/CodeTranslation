#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
vector<int> v(3030);
int n,k;
int tab[3030][3030][2];
int dp(int l,int r,bool pl){
    if(tab[l][r][pl]){
        return tab[l][r][pl];
    }
    if(l==r){
        return (pl ? -v[l] : v[l]);
    }
    if(pl){
        return tab[l][r][pl] = min(dp(l+1,r,!pl)-v[l],dp(l,r-1,!pl)-v[r]);
    }
    return tab[l][r][pl] = max(dp(l+1,r,!pl)+v[l],dp(l,r-1,!pl)+v[r]);
}
int32_t main(){
    ms(tab,0);
    fastio;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << dp(0,n-1,0) << endl;
} 