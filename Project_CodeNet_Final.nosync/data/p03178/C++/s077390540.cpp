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
const int N=1e4+10;
char s[N];
int n,d,mem[N][110][3],mod=1e9+7;
int dp(int ind,int sum,int ok){
if(ind==n){return (sum==0);}
int &ret=mem[ind][sum][ok];
if(ret!=-1){return ret;}
ret=0;
int dig=s[ind]-'0';
if(ok){
loop(i,0,9){ret+=dp(ind+1,(sum+i)%d,ok)%mod;ret%=mod;}
}
else{
loop(i,0,dig-1){ret+=dp(ind+1,(sum+i)%d,1)%mod;ret%=mod;}
ret+=dp(ind+1,(sum+dig)%d,0)%mod;
ret%=mod;
}
return ret;
}
int main(){
me(mem,-1);
scs(s);
sc(d);
n=strlen(s);
int ans=((dp(0,0,0)-1)+mod)%mod;
printf("%d\n",ans);
}

/**
**/
