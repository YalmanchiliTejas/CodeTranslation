#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

int main(){
  int i,j;
  string s;
  cin>>s;
  int k;
  cin>>k;
  int l=s.size();
  ll ans=0;
  vector<vector<int> > ok(l,vector<int>(l));
  for(i=0;i<l;i++){
    int z=0;
    for(j=i+1;j<l;j++){
      if(s[j]=='0'&&z==0) ok[i][j]=0;
      else if(z==0) {
        ok[i][j]=1;
        z=1;
      }
      else ok[i][j]=2;
    }
  } 

  if(k==3){
    for(i=0;i<l;i++){
      for(j=i+1;j<l;j++){
        for(int u=j+1;u<l;u++){
          if(i!=0){
            ans+=9*9*9;
          }
          else if(i==0){
            ans+=(s[0]-1-'0')*9*9;
            if(ok[i][j]==1){
              ans+=(s[j]-1-'0')*9;
              if(ok[j][u]==1){
                ans+=s[u]-'0';
              }
              else if(ok[j][u]==2) ans+=9;
            }
            else if(ok[i][j]==2) ans+=9*9;
          }
        }
      }
    }
  }
  else if(k==2){
    for(j=0;j<l;j++){
      for(int u=j+1;u<l;u++){
        if(j==0){
          ans+=(s[j]-1-'0')*9;
          if(ok[j][u]==1){
            ans+=s[u]-'0';
          }
          else if(ok[j][u]==2) ans+=9;
        }
        else {
          ans+=9*9;
        }
      }
    }
  }

  else if(k==1){
    ans+=s[0]-'0';
    for(j=1;j<l;j++){
      ans+=9;
    }
  }

  cout<<ans<<endl;
  


  
  return 0;
}

