#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using ll = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b)a=b;};
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b)a=b;};

const Int MOD = 1e6;
const Int MAX = 1024;
Int n;
Int dp[5][4][2][MAX];
string ss[MAX];

Int check(Int v,string s){
  for(Int i=0;i<8;i++){
    if((s[i]!='x')&&((s[i]-'0')!=(v&1))) return 0;
    v>>=1;
  }
  return 1;
}

Int rf[5][4],mc[5][4],ms[5][4];
Int match(Int a,Int b,Int l){
  return (a>>(8-l))==(b>>(8-l));
}

Int dfs(Int len,Int i,Int y,Int p){
  if(p==n) return (len==1&&i==0&&y==1);
  Int &res=dp[len][i][y][p];
  if(~res) return res;
  res=0;
  
  for(Int bit=0;bit<256;bit++){
    if(!check(bit,ss[p])) continue;
    if(!match(bit,rf[len][i],mc[len][i])) continue;
    if(i+1==len){
      if(y){
        for(Int nxt=1;nxt<=4;nxt++){
          Int ni=0;
          Int ny=(nxt==1);
          Int np=p+1;
          res+=dfs(nxt,ni,ny,np);
          res%=MOD;
        }
      }
    }else{
      Int ni=i+1;
      Int ny=y||(ms[len][i]&bit);
      Int np=p+1;
      res+=dfs(len,ni,ny,np);
      res%=MOD;
    }
  }
  return res;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);  

  rf[1][0]=0b00000000;
  
  rf[2][0]=0b11000000;
  rf[2][1]=0b10000000;

  rf[3][0]=0b11100000;
  rf[3][1]=0b10000000;
  rf[3][2]=0b10000000;

  rf[4][0]=0b11110000;
  rf[4][1]=0b10000000;
  rf[4][2]=0b10000000;
  rf[4][3]=0b10000000;
  
  mc[1][0]=1;
  
  mc[2][0]=3;
  mc[2][1]=2;

  mc[3][0]=4;
  mc[3][1]=2;
  mc[3][2]=2;

  mc[4][0]=5;
  mc[4][1]=2;
  mc[4][2]=2;
  mc[4][3]=2;
  
  ms[1][0]=0b00000000;
  
  ms[2][0]=0b00011110;
  ms[2][1]=0b00000000;

  ms[3][0]=0b00001111;
  ms[3][1]=0b00100000;
  ms[3][2]=0b00000000;

  ms[4][0]=0b00000111;
  ms[4][1]=0b00110000;
  ms[4][2]=0b00000000;
  ms[4][3]=0b00000000;
  
  while(cin>>n,n){
    memset(dp,-1,sizeof(dp));
    for(Int i=0;i<n;i++){
      cin>>ss[i];
      reverse(ss[i].begin(),ss[i].end());
    }
    Int ans=0;
    for(Int len=1;len<=4;len++){
      ans+=dfs(len,0,(len==1),0);
      ans%=MOD;
    }
    cout<<ans<<endl;
  }
  return 0;
}

