#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
  for(string str;cin>>str,str[0]!='#';){
    int len=str.size();
    string m;
    for(int i=1;i<len;i++){
      int dp[300][300]={};
      for(int j=0;j<i;j++){
	for(int k=0;i+k<len;k++){
	  dp[j+1][k+1]=max(dp[j][k+1],max(dp[j+1][k],dp[j][k]+(str[j]==str[i+k])));
	}
      }
      int y=i,x=len-i;
      string c;
      while(dp[y][x]){
       if(y&&dp[y-1][x]==dp[y][x]){
	 y--;
       }else if(x&&dp[y][x-1]==dp[y][x]){
	 x--;
       }else{
	 c+=str[y-1];
	 y--;
	 x--;
       }
      }
      if(c.size()>m.size()){
	m=c;
      }
    }
    cout<<string(m.rbegin(),m.rend())<<endl;
  }
}