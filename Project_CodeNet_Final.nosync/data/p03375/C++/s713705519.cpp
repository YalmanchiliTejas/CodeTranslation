#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll add(ll x,ll y,ll mod){return (x+y)%mod;}
ll mul(ll x,ll y,ll mod){return (x*y)%mod;}

ll mpow(ll x,ll y,ll mod){
  ll v=1;
  for(;y;x=mul(x,x,mod),y>>=1)
    if(y&1)v=mul(v,x,mod);
  return v;
}

ll divi(ll x,ll y,ll mod){return mul(x,mpow(y,mod-2,mod),mod);}

ll ncr[5000][5000];

ll nCr(ll n,ll r,ll mod){
  if(n==r)return 1;
  if(r==0)return 1;
  if(ncr[n][r])return ncr[n][r];
  ncr[n][r]=(nCr(n-1,r-1,mod)+nCr(n-1,r,mod))%mod;
  return ncr[n][r];
}


/*

void solve(){
  map<int,int> mp;
  vector<ll> v;
  for(int i=1;i<8;i++)v.push_back(i);
  
  int size=v.size();
  for(int i=0;i<(1<<size);i++){
    ll A=0;
    bool flag=true;
    for(int j=0;j<size;j++){
      if(i>>j&1){
        if( (A&v[j]) > 0 )flag=false;
        A|=v[j];
      }
    }
    if(flag){
      int w= __builtin_popcount(i);
      mp[ w ] ++;
    }
  }
  for(int i=0;i<=8;i++){
    cout<<i<<' '<<mp[i]<<endl;
  }

}
*/

ll N,M;
ll dp[3005][3005];

void solve(){
  for(int i=0;i<3005;i++)
    for(int j=0;j<3005;j++)
      dp[i][j]=0;
  
  dp[0][0]=1;
  for(int i=0;i<N+1;i++){
    for(int j=0;j<N+1;j++){
      dp[i][j+1]+=dp[i][j];
      dp[i][j+1]+=dp[i][j]*i;
      dp[i][j+1]%=M;
      
      dp[i+1][j+1]+=dp[i][j];
      dp[i+1][j+1]%=M;
    }
  }
}

int main(){
  
  cin>>N>>M;
  solve();

  ll count= mpow(2, N, M-1 );
  
  ll base = mpow( 2, count, M );

  ll ans=0;
  for(int i=1;i<=N;i++){
    
    ll other = mpow( 2, N-i, M-1);
    ll p_other = mpow( 2, other ,M);

    other = mpow( 2, N-i, M);
    ll val=1;
    for(int j=1;j<=N;j++)
      val = add(val ,  dp[j][i]*mpow(other,j,M)   ,M);

    ll tmp= mul( val, p_other , M);
    ll k=nCr(N,i,M);
    tmp=mul(tmp,k, M);
    if(i%2==1)ans=add(ans,tmp, M);
    else ans=add(ans, M-tmp, M);
    
  }

  cout<< add( base, M - ans , M) <<endl;
  return 0;
}
