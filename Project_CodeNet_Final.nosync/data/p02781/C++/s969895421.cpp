#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(i,e) for(ll i=0;i<e;i++ )
typedef pair<ll,ll> P;
const ll mod = 1e9+7;
const ll INF = INT64_MAX;

ll i,j;

string N;
ll K;
ll dp1[100][4];
ll dp0[100][4];

ll k0(ll x,ll y){
   if(y==-1)return 0;
   if(dp0[x][y]>=0)return dp0[x][y];
   if(x==0){
      if(y==1)return dp0[x][y]=1;
      else return dp0[x][y]=0;
   }
   else{
      int c=N[x]-'0';
      if(c==0)return dp0[x][y]=k0(x-1,y);
      else return dp0[x][y]=k0(x-1,y-1);
   }
}

ll k1(ll x,ll y){
   if(y==-1)return 0;
   if(dp1[x][y]>=0)return dp1[x][y];
   int c=N[x]-'0';
   if(x==0){
      if(y==1)return c-1;
      else if(y==0)return 1;
      return 0;
   }
   else{
      if(c==0)return dp1[x][y]=k1(x-1,y)+k1(x-1,y-1)*9;
      return dp1[x][y]=k1(x-1,y)+k1(x-1,y-1)*9+k0(x-1,y)+k0(x-1,y-1)*(c-1);
   }
}
int main(){
   cin>>N;
   cin>>K;
   ll keta=N.length();


   rep(i,keta){
      rep(j,K+1){
         dp1[i][j]=-1;
         dp0[i][j]=-1;
      }
   }

   
   ll ans=k0(keta-1,K)+k1(keta-1,K);
   cout<<ans<<endl;
   
   
   

}
