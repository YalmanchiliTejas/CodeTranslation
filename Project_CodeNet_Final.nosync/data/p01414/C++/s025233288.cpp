#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(){
  int n,v=1<<16,i,j,k,l,a,b,x,y,z,bit,d;
  cin>>n;
  int h[n],w[n],dp[v],used[v];
  for(i=0;i<n;i++) cin>>h[i]>>w[i];
  string s[4],c="RGB";;
  for(i=0;i<4;i++) cin>>s[i];
  memset(dp,-1,sizeof(dp));
  memset(used,0,sizeof(used));
  queue<P> q;
  q.push(P(0,0));
  while(!q.empty()){
    bit=q.front().first,d=q.front().second;
    q.pop();
    if(~dp[bit]) continue;
    dp[bit]=d;
    for(i=0;i<n;i++)
      for(j=-h[i]+1;j<4;j++)
	for(k=-w[i]+1;k<4;k++)
	  for(l=0;l<3;l++){
	    for(z=bit,a=max(0,-j);a<min(h[i],4-j);a++)
	      for(b=max(0,-k);b<min(w[i],4-k);b++){
		y=j+a,x=k+b;
		if(s[y][x]==c[l]) z|=1<<(y*4+x);
		else z&=v-1-(1<<(y*4+x));
	      }
	    if(dp[z]<0&&!used[z]) q.push(P(z,d+1)),used[z]=1;
	  }
  }
  cout<<dp[v-1]<<endl;
  return 0;
}