#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
ll dp[1010][1010];
ll mod_div(ll a,ll b){
  ll tmp=MOD-2,c=b,ret=1;
  while(tmp>0){
    if(tmp&1){
      ret*=c;ret%=MOD;
    }
    c*=c;c%=MOD;tmp>>=1;
  }
  return a*ret%MOD;
}
 
#define MAX_K 200100
vector<ll> kaijo(MAX_K);
ll comb[1010][1010];
ll combination(ll n, ll r){
  if(n<r||n<0||r<0)
    return 0;
  if(comb[n][r])return comb[n][r];
  if(kaijo[0]!=1){
    kaijo[0]=1;
    for(ll i=1;i<MAX_K;i++)kaijo[i]=(kaijo[i-1]*i)%MOD;
  }
  ll ret=kaijo[n];
  long long tmp = (kaijo[r] * kaijo[n-r]) % MOD;
  return comb[n][r]=mod_div(ret,tmp);
}

void modadd(ll &a, ll b){
  a+=b;
  a%=MOD;
}


//べき乗 x^n mod M
long long power(long long x, long long n){
	long long res = 1;
	if(n > 0){
		res = power(x, n / 2);
		if(n % 2 == 0) res = (res * res) % MOD;
		else res = (((res * res) % MOD) * x ) % MOD;
	}
	return res;
}

//階乗
long long fact[1005];
long long factorial(long long n, long long r){
	long long res = 1;
	for(int i=r;i<n + 1;i++){
		res*= i;
		res%= MOD;
		fact[i] = res;
	}
	return res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  dp[a-1][n]=1;
  factorial(1000,1);
  ll fact_rev[1005];
  for(int i=0;i<1001;i++)fact_rev[i]=power(fact[i],MOD-2);
  for(int i=a-1;i<b;i++){
    for(int j=0;j<=n;j++){
      ll kake=1;
      int cnt=1;
      if(dp[i][j]==0)continue;
      for(int k=j-(i+1);k>=0;k-=(i+1)){
	if(cnt>d)break;
	//cout<<i<<" "<<j<<" "<<k+1+i<<" "<<i+1<<endl;
	if(cnt>=c){
	  dp[i+1][k]+=(dp[i][j]*((combination(k+i+1,i+1)*kake%MOD*fact_rev[cnt])%MOD))%MOD;
	  
	}
	dp[i+1][k]%=MOD;
	kake*=combination(k+1+i,i+1);
	kake%=MOD;
	cnt++;
      }
      dp[i+1][j]+=dp[i][j];
      dp[i+1][j]%=MOD;
    }
  }

  /* for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      //if(dp[i][j]<0)
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
    }*/
  cout<<dp[b][0]<<endl;
  return 0;
}
