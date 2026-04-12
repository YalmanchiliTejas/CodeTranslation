#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void fastIO(){
  ios_base::sync_with_stdio(0); cin.tie(0);
}


int main(){
  fastIO();
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(a+b<=c*2){
  	cout<<(a*x)+(b*y)<<endl;
  }else{
  	int ans = 0;
  	ans+=min(x,y)*c*2;
  	if(x>y){
  	  x-=y;
  	  if(a<=c*2){
  	  	ans+=x*a;
  	  }else{
  	  	ans+=x*c*2;
  	  }
  	}else{
  	  y-=x;
  	  if(b<=c*2){
  	  	ans+=y*b;
  	  }else{
  	  	ans+=y*c*2;
  	  }
  	}
  	cout<<ans<<endl;
  }
}


