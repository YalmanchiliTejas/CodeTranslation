#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;

int main(){

  ll H,W=0;

  cin>>H>>W;  
	
  string s[H];
  rep(i,H){

    cin>>s[i];
    
  }
  
  map<int,int> mp1;
  map<int,int> mp2;
  
  
  rep(i,H){
    mp1[i]=0;
    
    int flag=0;
    rep(j,W){

      if(s[i][j]=='#')flag=1;
      
    }
    if(flag==0)mp1[i]=1;
    flag=0;
  }
  
  
  rep(j,W){
    mp2[j]=0;
    
    int flag=0;
    rep(i,H){

      if(s[i][j]=='#')flag=1;

    }
    if(flag==0)mp2[j]=1;
    flag=0;
    
  }
  
  rep(i,H){

    rep(j,W){

      if(mp1[i]==0 && mp2[j] ==0)cout<<s[i][j];
      
    }
    if(mp1[i]==0)cout<<endl;
    
  
  }

}