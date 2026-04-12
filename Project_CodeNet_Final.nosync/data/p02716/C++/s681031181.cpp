#pragma GCC target("avx")
//#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define DB double
#define ST string
#define BS bitset
#define PA pair<LL,LL>
#define VE vector
#define VL vector<LL>
#define VP vector<pair<LL,LL>>
#define VVL vector<vector<LL>>
#define PQ priority_queue
#define PQS priority_queue<LL,vector<LL>,greater<LL>>
#define PB push_back
#define POB pop_back
#define PF push_front
#define POF pop_front
#define EB emplace_back
#define MP make_pair
#define TS to_string
#define TU to_ullong
#define BPL __builtin_popcountll
#define FOR(i,a,n) for(i=a;i<n;i++)
#define FORR(i,a,n) for(i=n-1;i>=a;i--)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) FOR(i,0,n)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define UB(a,n) *upper_bound(ALL(a),n)
#define LB(a,n) *lower_bound(ALL(a),n)
#define INF 1145141919810364364
#define PI 3.14159265358979
#define MOD 1000000007
//#define MOD 998244353
#define ERR 0.00000001
//#define ERR 0.00000000000001
#define NUM 200010
#define FAST cin.tie(0);ios::sync_with_stdio(false)

void Yn(LL a){if(a)printf("Yes\n");else printf("No\n");}
void YN(LL a){if(a)printf("YES\n");else printf("NO\n");}
LL pwmn(LL a,LL n){LL ans=1;while(ans<a)ans*=n;return ans;}
LL LBn(VL &v,LL a){LL mx=v.size(),mn=-1,md;while(mx-mn>1){md=(mx+mn)/2;if(v[md]<a)mn=md;else mx=md;}return mx;}
LL GCD(LL a,LL b){LL c=1,tmp=max(a,b);b=min(a,b);a=tmp;while(c!=0){c=a%b;a=b;b=c;}return a;}
LL LCM(LL a,LL b){return a*b/GCD(a,b);}
int lcmp(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return 1;if(*(LL*)a<*(LL*)b)return -1;return 0;}
int lcmpr(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return -1;if(*(LL*)a<*(LL*)b)return 1;return 0;}
int ccmp(const void* a,const void* b){return *(char*)a-*(char*)b;}
int ccmpr(const void* a,const void* b){return *(char*)b-*(char*)a;}
int scmp(const void* a,const void* b){return strcmp((char*)a,(char*)b);}
int scmpr(const void* a,const void* b){return strcmp((char*)b,(char*)a);}
LL mod(LL a,LL m){if(a<0)return a%m+m;else return a%m;}
LL DIV(LL a,LL d){LL m=MOD,x=1,y=0,k;while(m){k=d/m;d-=k*m;swap(m,d);x-=k*y;swap(x,y);}return mod(a*mod(x,MOD),MOD);}
LL POW(LL a,LL n){LL ans=1;while(n>0){if(n&1)ans=ans*a%MOD;a=a*a%MOD;n>>=1;}return ans;}
LL fact[NUM],finv[NUM],inv[NUM];
void comi(){LL i;fact[0]=fact[1]=1;finv[0]=finv[1]=1;inv[1]=1;FOR(i,2,NUM){fact[i]=fact[i-1]*i%MOD;inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
LL com(LL n,LL k){if(n<k||n<0||k<0)return 0;return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;}
bool cmps(pair<LL,LL> a,pair<LL,LL> b){if(a.second!=b.second)return a.second<b.second;return a.first<b.first;}
template<typename T>bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main(){
  FAST;
  LL i,j,ans=-INF,N;
  cin>>N;
  LL A[N],dp[N][3];
  rep(i,N){
    cin>>A[i];
    rep(j,3)dp[i][j]=-INF;
  }
  dp[0][0]=dp[0][1]=0,dp[0][2]=A[0];
  dp[1][0]=0,dp[1][1]=dp[1][2]=A[1];
  rep(i,N-1){
    if(i%2){
      dp[i+1][0]=max(dp[i][1],dp[i+1][0]);
      dp[i+1][1]=dp[i+1][0];
    }else{
      dp[i+1][2]=max(dp[i][2],dp[i+1][2]);
      dp[i+1][1]=dp[i+1][2];
    }
    if(i+2<N){
      rep(j,3)dp[i+2][j]=max(dp[i+2][j],dp[i][j]+A[i+2]);
      dp[i+2][0]=max(dp[i+2][0],dp[i][2]);
      if(i%2)dp[i+2][1]=dp[i+2][2];
      else dp[i+2][1]=dp[i+2][0];
    }
    if(i+3<N){
      dp[i+3][1]=dp[i][2]+A[i+3];
      if(i%2)dp[i+3][0]=dp[i+3][1];
      else dp[i+3][2]=dp[i+3][1];
    }
  }
  /*rep(i,N){
    rep(j,3)cout<<dp[i][j]<<" ";
    cout<<endl;
  }*/
  if(N%2)rep(i,2)chmax(ans,dp[N-1][i]);
  else rep(i,2)chmax(ans,dp[N-1][i+1]);
  cout<<ans<<endl;
}
