#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;

void calcXAndOne(string s1,int f,int t,ll &x,ll &o){
  for(int i = f; i <= t; i++){
    if(s1[i]=='1')
      o++;
    else if(s1[i]=='x')
      x++;
  }
}

bool match(string s1,string s2){
  for(int i = 0; i < s1.size(); i++){
    if(s1[i]==s2[i]||s1[i]=='x')continue;
    else return false;
  }
  return true;
}

const ll MOD=1000000;
int main(){

  int n;
  while(cin>>n&&n!=0){
    string ss[1001];
    ll dp[1001];
    fill(dp,dp+1001,0);
    for(int i = 0; i < n; i++)
      cin>>ss[i];
    for(int i = 0; i < n; i++){
      ll tmp;
      ll sumX=0;
      ll o=0;
      if(i-1>=-1){
	sumX=o=0;
	if(i-1==-1)
	  tmp=1;
	else
	  tmp=dp[i-1];
	if(match(ss[i].substr(0,1),"0")){
	  calcXAndOne(ss[i],1,7,sumX,o);
	  for(int j = 0; j < sumX; j++){
	    tmp*=2;
	    tmp%=MOD;
	  }
	  dp[i]+=tmp;
	}
      }
      if(i-2>=-1){
	sumX=o=0;
	if(i-2==-1)
	  tmp=1;
	else
	  tmp=dp[i-2];
	if(match(ss[i-1].substr(0,3),"110")&&match(ss[i].substr(0,2),"10")){
	  calcXAndOne(ss[i-1],3,6,sumX,o);
	  if(sumX+o>=1){
	    if(o<=0){
	      ll tt=1;
	      for(int j = 0; j < sumX; j++){
		tt*=2;
	      }
	      tt--;
	      tt%=MOD;
	      sumX=0;
	      tmp*=tt;
	      tmp%=MOD;
	    }
	    else{
	      for(int j = 0; j < sumX; j++){
		tmp*=2;
		tmp%=MOD;
	      }
	      sumX=0;
	    }
	    
	    calcXAndOne(ss[i-1],7,7,sumX,o);
	    calcXAndOne(ss[i],2,7,sumX,o);
	    for(int j = 0; j < sumX; j++){
	      tmp*=2;
	      tmp%=MOD;
	    }
	    dp[i]+=tmp;
	  }
	}
      }
      if(i-3>=-1){
	sumX=o=0;
	if(i-3==-1)
	  tmp=1;
	else
	  tmp=dp[i-3];
	if(match(ss[i-2].substr(0,4),"1110")
	   &&match(ss[i-1].substr(0,2),"10")&&match(ss[i].substr(0,2),"10")){
	  calcXAndOne(ss[i-2],4,7,sumX,o);
	  calcXAndOne(ss[i-1],2,2,sumX,o);
	  if(sumX+o>=1){
	    if(o<=0){
	      ll tt=1;
	      for(int j = 0; j < sumX; j++){
		tt*=2;
	      }
	      tt--;
	      tt%=MOD;
	      sumX=0;
	      tmp*=tt;
	      tmp%=MOD;
	    }
	    else{
	      for(int j = 0; j < sumX; j++){
		tmp*=2;
		tmp%=MOD;
	      }
	      sumX=0;
	    }
	    calcXAndOne(ss[i-1],3,7,sumX,o);
	    calcXAndOne(ss[i],2,7,sumX,o);
	    for(int j = 0; j < sumX; j++){
	      tmp*=2;
	      tmp%=MOD;
	    }
	    dp[i]+=tmp;
	  }
	}
      }
      if(i-4>=-1){
	sumX=o=0;
	if(i-4==-1)
	  tmp=1;
	else
	  tmp=dp[i-4];
	if(match(ss[i-3].substr(0,5),"11110")
	   &&match(ss[i-2].substr(0,2),"10")
	   &&match(ss[i].substr(0,2),"10")&&match(ss[i-1].substr(0,2),"10")){
	  calcXAndOne(ss[i-3],5,7,sumX,o);
	  calcXAndOne(ss[i-2],2,3,sumX,o);
	  if(sumX+o>=1){
	    if(o<=0){
	      ll tt=1;
	      for(int j = 0; j < sumX; j++){
		tt*=2;
	      }
	      tt--;
	      tt%=MOD;
	      sumX=0;
	      tmp*=tt;
	      tmp%=MOD;
	    }
	    else{
	      for(int j = 0; j < sumX; j++){
		tmp*=2;
		tmp%=MOD;
	      }
	      sumX=0;
	    }
	    calcXAndOne(ss[i-2],4,7,sumX,o);
	    calcXAndOne(ss[i-1],2,7,sumX,o);
	    calcXAndOne(ss[i],2,7,sumX,o);
	    for(int j = 0; j < sumX; j++){
	      tmp*=2;
	      tmp%=MOD;
	    }
	    dp[i]+=tmp;
	  }
	}
      }
      dp[i]%=MOD;
    }
    cout<<dp[n-1]<<endl;
  }
  return 0;
}