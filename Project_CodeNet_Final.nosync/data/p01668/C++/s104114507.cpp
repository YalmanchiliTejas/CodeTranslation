#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

int dp[10005][2][2];

void DP(string A, string B, string C){
  
  while(A.size()<B.size()) A='0'+A;
  
  int ans=0;
  
  for(int i=0;i<A.size();i++){
    
    if(i+C.size()-1>=A.size()) break;
    
    memset(dp,0,sizeof(dp));
    
    for(int j=A[0];j<=B[0];j++){
      int a=1, b=1;
      if(j==A[0]) a=0;
      if(j==B[0]) b=0;
      if(!i){
	a=1, b=1;
	if(C[0]==A[0]) a=0;
	if(C[0]==B[0]) b=0;
	if(C[0]<A[0]) continue;
	if(B[0]<C[0]) continue;
	dp[1][a][b]++;
	break;
      }
      dp[1][a][b]++;
    }
    
    for(int j=1;j<A.size();j++){
      
      for(int k=0;k<2;k++){
	for(int l=0;l<2;l++){
	  
	  if(!dp[j][k][l]) continue;
	  
	  for(int num='0';num<='9';num++){
	    
	    if(i<=j&&j<=i+C.size()-1){
	      num=C[j-i];
	      if(k==0&&num<A[j]) break;
	      if(l==0&&num>B[j]) break;
	    }
	    
	    if(k==0&&num<A[j]) continue;
	    if(l==0&&num>B[j]) continue;
	    
	    int nk=k, nl=l;
	    if(!nk&&A[j]<num) nk=1;
	    if(!nl&&B[j]>num) nl=1;
	    
	    dp[j+1][nk][nl]=(dp[j+1][nk][nl]+dp[j][k][l])%M;
	    
	    if(i<=j&&j<=i+C.size()-1) break;
	  }
	  
	}
      }
      
    }
    
    for(int j=0;j<2;j++)
      for(int k=0;k<2;k++) ans=(ans+dp[A.size()][j][k])%M;
    
  }
  
  cout<<ans<<endl;
}

int dp2[10005][2][2][2];

void DP2(string A, string B, string C){
  
  int ans=0;
  
  if(A=="0") ans=1;
  
  while(A.size()<B.size()) A='0'+A;
  
  for(int i=1;i<A.size();i++){
    
    memset(dp2,0,sizeof(dp2));
    
    for(int j=A[0];j<=B[0];j++){
      int a=1, b=1;
      if(j==A[0]) a=0;
      if(j==B[0]) b=0;
      if(j=='0') dp2[1][a][b][0]++;
      else dp2[1][a][b][1]++;
    }
    
    for(int j=1;j<A.size();j++){
      
      for(int k=0;k<2;k++)
	
	for(int l=0;l<2;l++){
	  
	  for(int m=0;m<2;m++){
	    
	    if(!dp2[j][k][l][m]) continue;
	    
	    if(j==i){
	      
	      int nk=k, nl=l;
	      
	      if( nk == 0 && '0' < A[j] ) continue;
	      if( nl == 0 && '0' < B[j] ) nl=1;
	      
	      dp2[j+1][nk][nl][m]=(dp2[j+1][nk][nl][m]+dp2[j][k][l][m])%M;
	      
	    }else{
	      
	      for(int num='0';num<='9';num++){
		
		int nk=k, nl=l;
		
		if( nk == 0 && num < A[j] ) continue;
		if( nl == 0 && B[j] < num ) continue;
		
		if( nk == 0 && A[j] < num ) nk=1;
		if( nl == 0 && num < B[j] ) nl=1;
		
		if(m==0){
		  
		  if(num=='0') dp2[j+1][nk][nl][0]=(dp2[j+1][nk][nl][0]+dp2[j][k][l][0])%M;
		  else if(j<=i) dp2[j+1][nk][nl][1]=(dp2[j+1][nk][nl][1]+dp2[j][k][l][0])%M;
		  
		}
		else dp2[j+1][nk][nl][1]=(dp2[j+1][nk][nl][1]+dp2[j][k][l][1])%M;
		
	      }
	      
	    }
	    
	  }
	}
      
    }
    
    for(int j=0;j<2;j++)
      for(int k=0;k<2;k++) ans=(ans+dp2[A.size()][j][k][1])%M;
    
  }
  
  cout<<ans<<endl;
}

string A, B, C;

int main(){

  cin>>A>>B>>C;

  if(C=="0") DP2(A, B, C);
  
  else DP(A, B, C);
    
  return 0;
}