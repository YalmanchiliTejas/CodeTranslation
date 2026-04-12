#include <bits/stdc++.h>
#define F first
#define S second
#define ld long douroote
#define pb push_back
#define sz size
#define ll long long
#define ull unsigned long long
#define INF 0x7f7f7f7f
#define sc(a) scanf("%d",&a)
#define scll(a) scanf("%lld",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf(" %c",&a)
#define scs(a) scanf(" %s",a)
#define me(a,b) memset(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define allr(a,n) a,a+n
#define loop(a,s,e) for(ll a=s;a<=e;a++)
#define read_arr(a,s,n) for(int i=s;i<n+s;i++){sc(a[i]);}
#define read_arr_ll(a,s,n) for(int i=s;i<n+s;i++){scll(a[i]);}
#define err(a,s) cerr<<a<<s;
#define err_arr(a,s,n) for(int i=s;i<n+s;i++){cerr<<a[i]<<" ";}cerr<<endl;
#define prtll(x) printf("%lld",x);
#define prt(x) printf("%d",x);
using namespace std;
const int N=3e3+10;
ll n,a[N],oo=1e13,sum;
ll mem[N][N][3];
ll dp(int i,int j,int p){
if(i>j){return 0;}
if(i==j){return (p?a[i]:0);}
ll &ret=mem[i][j][p];
if(ret!=-1){return ret;}
ret=-oo;
if(p){
ret=max(a[i]+dp(i+1,j,!p),a[j]+dp(i,j-1,!p));
}
else{
ret=min(dp(i+1,j,!p),dp(i,j-1,!p));
}
return ret;
}
int main(){
me(mem,-1);
scll(n);
read_arr_ll(a,1,n);
loop(i,1,n){sum+=a[i];}
ll ans=2*dp(1,n,1)-sum;
printf("%lld\n",ans);
}
/**
**/
