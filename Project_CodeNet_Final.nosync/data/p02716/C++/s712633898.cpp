#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stack>
#include<bitset>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define dbg(a) cout<<"* "<< #a <<" : "<<a<<endl
#define fr first
#define se second
#define ls x<<1
#define rs x<<1|1
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define lowbit(x) x&(-x)
#define ac cout<<ans<<endl
//#define DEBUG 0
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
const ull hashp=131;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+100;
ll sum[2][maxn];
int a[maxn];
void solve(){
	int n;scd(n);
	rep1(i,n)scd(a[i]);
	ll ans=0;
	for(int i=n-1-(n&1);i>=1;i-=2){
		ans+=1ll*a[i];
		sum[0][i]=sum[0][i+2]+a[i+1]-a[i];
		if(n&1)sum[1][i]=sum[1][i+2]+a[i+2]-a[i+1];
	}
	if(n&1){
		ll mx=0,mark=0;
		for(int i=n-1-(n&1);i>=1;i-=2){
			mx=max(mx,sum[1][i]);
			mark=max(mark,sum[0][i]+mx);
		}
		ans+=mark;
	}
	else {
		ll mx=0;
		for(int i=1;i<=n;i+=2)
			mx=max(mx,sum[0][i]);
		ans+=mx;
	}
	ac;
}
int main(){
    //IOS;
    //freopen("fenwick.in","r",stdin);
    //freopen("fenwick.out","w",stdout);
    solve();
    
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;                                             ;;
	;;         ;;            ;;;;;;;;;       ;;    ;;
	;;        ;; ;;        ;;                ;;    ;;
	;;       ;;   ;;       ;;                ;;    ;;
	;;      ;;;;;;;;;      ;;                ;;    ;;
	;;     ;;       ;;     ;;                      ;;
    ;;    ;;         ;;      ;;;;;;;;;       ;;    ;;
    ;;                                             ;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
    return 0;
}