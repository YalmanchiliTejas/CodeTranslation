/*input
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
3
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
typedef unsigned long long int ll;
#define ld double
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
const ll maxn=2e3+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
ll mult(ll a,ll b){
    return (a*b)%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}
ll dp[4][105][2];
int k;
string s;
ll rec(int cnt,int len,int same){
	if(cnt>k) return 0;
    if(len>=sz(s)){
        if(cnt==k) return 1;
        return 0;
    }
    if(dp[cnt][len][same]!=-1) return dp[cnt][len][same];
    ll ans=0;
    REP(i,10){
        if(same and i>s[len]-'0') break;
        if(i!=0){
            if(same and i==s[len]-'0') ans+=rec(cnt+1,len+1,same);
            else ans+=rec(cnt+1,len+1,0);
        }
        else{
            if(same and i==s[len]-'0') ans+=rec(cnt,len+1,same);
            else ans+=rec(cnt,len+1,0);        	
        }
    }
    return dp[cnt][len][same]=ans;
}
ll f(){
    REP(i,4) REP(j,105) REP(z,2) dp[i][j][z]=-1;
    ll ans=0;
    REP1(i,s[0]-'0'){
        ans+=rec(1,1,i==(s[0]-'0'));
    }
    for(int k=2;k<=sz(s);k++){
        ans+=9LL*rec(1,k,0);
    } 
    return ans;
}
int main(){
    cin>>s>>k;
    cout<<f();
}