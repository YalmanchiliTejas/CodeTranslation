#include<bits/stdc++.h>
using namespace std;
using Int = long long;
const Int MOD=1000000007;
signed main(){
  string a,b,c;
  cin>>a>>b>>c;
  if(a=="0"){
    a="$";
  }else{
    for(Int i=(Int)a.size();i>0;i--){
      if(a[i-1]!='0'){
	a[i-1]--;
	break;
      }
    }
  }
  //cout<<a<<" "<<b<<endl;
  vector<vector<Int> > dp2(c.size()+1,vector<Int>(10,0));
  if(c.size()>1){
    Int n=c.size();
    vector<Int> dp(n+1,0);
    dp[0]=-1;dp[1]=0;
    Int i=2,j=0;
    while(i<=(Int)n){
      if(c[i-1]==c[j]){
	dp[i]=j+1;
	i++;j++;
      }else if(j>0){
	j=dp[j];
      }else{
	dp[i]=0;
	i++;
      }
    }
    //cout<<c<<endl;
    //for(Int i=0;i<=n;i++) cout<<i<<" "<<dp[i]<<endl;
    //for(Int j=0;j<10;j++) dp2[0][j]=(c[0]-'0'==j);
    for(Int i=0;i<=n;i++){
      for(Int j=0;j<10;j++){
	//cout<<i<<" "<<j<<endl;
	Int k=i;
	while(k>=0&&c[k]-'0'!=j){
	  //cout<<k<<endl;
	  k=dp[k];
	}
	if(k<0) k++;
	if(c[k]-'0'==j) k++;
	dp2[i][j]=k;
	
	//cout<<i<<" "<<j<<":"<<dp2[i][j]<<endl;
      }
    }
  }else{
    dp2[0][c[0]-'0']=dp2[1][c[0]-'0']=1;
  }
  
  auto calc=[&](string s,string t){
    if(s=="$") return 0LL;
    Int res=0;
    Int n=s.size(),m=t.size();
    vector<vector<Int> > po(2,vector<Int>(n+1,0));
    po[0][n]=po[1][n]=1;
    for(Int i=n;i>0;i--){
      po[1][i-1]=po[1][i]*10%MOD;
      po[0][i-1]=((s[i-1]-'0')*po[1][i]%MOD+po[0][i])%MOD;
    }

    vector<vector<vector<Int> > > dp(2,vector<vector<Int> >(n+1,vector<Int>(m+1,0)));
    if(t!="0"){
      dp[0][0][0]=1;
      for(Int k=0;k<2;k++){
	for(Int i=0;i<n;i++){
	  for(Int j=0;j<=m;j++){
	    if(i==0&&j==0&&t=="0") continue;
	    for(Int a=0;a<10;a++){
	      if(!k&&a>(s[i]-'0')) continue;
	      //cout<<k<<" "<<i<<" "<<j<<" "<<a<<":"<<(k||(a<(s[i]-'0')))<<" "<<dp2[j][a]<<endl;
	      dp[k||(a<(s[i]-'0'))][i+1][dp2[j][a]]+=dp[k][i][j];
	      dp[k||(a<(s[i]-'0'))][i+1][dp2[j][a]]%=MOD;
	    }
	  }
	  //cout<<k<<" "<<i<<":"<<dp[k][i][m]<<" "<<po[k][i]<<endl;
	  res+=dp[k][i][m]*po[k][i];
	  res%=MOD;
	}
      }
      //cout<<dp[0][n][m]<<" "<<dp[1][n][m]<<endl;
      res+=dp[0][n][m]+dp[1][n][m];
      res%=MOD;
    }else{
      res=1;
      dp[0][0][0]=1;
      for(Int k=0;k<2;k++){
	for(Int i=0;i<n;i++){
	  for(Int j=0;j<2;j++){
	    for(Int a=0;a<10;a++){
	      if(!k&&a>(s[i]-'0')) continue;
	      //cout<<k<<" "<<i<<" "<<j<<" "<<a<<":"<<(k||(a<(s[i]-'0')))<<" "<<dp2[j][a]<<endl;
	      dp[k||(a<(s[i]-'0'))][i+1][j||a]+=dp[k][i][j];
	      dp[k||(a<(s[i]-'0'))][i+1][j||a]%=MOD;
	    }
	  }
	  //cout<<k<<" "<<i<<":"<<dp[k][i][1]<<" "<<po[1][i+1]<<endl;
	 
	  
	  res+=dp[k][i][1]*po[!(!k&&s[i]=='0')][i+1];
	  res%=MOD;
	}
      }
    }
    return res;
  };
  Int ans=0;
  ans+=calc(b,c);
  ans%=MOD;
  ans+=MOD-calc(a,c);
  ans%=MOD;
  cout<<ans<<endl;
  return 0;
}