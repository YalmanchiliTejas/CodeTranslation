#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
  int g,h,i,j,k,l,m;
  int n;
  cin>>n;
  int y[16],x[16];
  for(i=0;i<n;++i)
    cin>>y[i]>>x[i];
  int a[4][4];
  for(i=0;i<4;++i){
    for(j=0;j<4;++j){
      char s;
      cin>>s;
      if(0){
      }else if(s=='R'){
	a[i][j]=1;
      }else if(s=='G'){
	a[i][j]=2;
      }else if(s=='B'){
	a[i][j]=3;

      }
    }
  }
  vector<pair<int,int> > b;
  b.reserve(300);
  for(i=0;i<4;++i){
    for(j=0;j<4;++j){
      for(k=i;k<4;++k){
	for(l=j;l<4;++l){
	  for(m=0;m<n;++m){
	    if(0){
	    }else if((i==0||k==3)&&(j==0||l==3)){
	      if(k-i+1<=y[m]&&l-j+1<=x[m])
		break;
	    }else if(i==0||k==3){
	      if(k-i+1<=y[m]&&l-j+1==x[m])
		break;
	    }else if(j==0||l==3){
	      if(k-i+1==y[m]&&l-j+1<=x[m])
		break;
	    }else{
	      if(k-i+1==y[m]&&l-j+1==x[m])
		break;
	    }
	  }
	  if(m==n)
	    continue;
	  for(m=0;m<3;++m){
	    int p=0,q=0,r=0;
	    for(g=0;g<4;++g){
	      for(h=0;h<4;++h){
		if(i<=g&&g<=k&&j<=h&&h<=l){
		  p|=1;
		  if(a[g][h]==m+1){
		    q|=1;
		    r=-1;
		  }
		}
		if(g!=3||h!=3){
		  p<<=1;
		  q<<=1;
		}
	      }
	    }
	    if(!r)
	      continue;
	    p=~p;
	    b.push_back(make_pair(p,q));
	  }
	}
      }
    }
  }
  bool c[1<<16]={};
  c[0]=true;
  queue<pair<int,int> > d;
  d.push(make_pair(0,0));
  while(!d.empty()){
    int p,q;
    p=d.front().first;
    q=d.front().second;
    if(p==(~(-1<<16)))
      break;
    d.pop();
    for(i=0;i<(int)b.size();++i){
      int r=(p&b[i].first)|b[i].second;
      if(c[r])
	continue;
      c[r]=true;
      d.push(make_pair(r,q+1));
    }
  }
  cout<<d.front().second<<endl;
  return 0;
}