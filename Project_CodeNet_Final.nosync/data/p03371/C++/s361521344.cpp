#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int a,b,c,x,y;
  	long long ans,ans1=0,ans2=0;
  	cin>>a>>b>>c>>x>>y;
  
  	if(a+b<2*c){
		cout<<a*x+b*y<<endl;
      	return 0;
    }else{
          if(x>y){
			ans1+=c*2*y+a*(x-y);
            ans2+=c*2*x;
          }else{
			ans1+=c*2*x+b*(y-x);
            ans2+=c*2*y;
          }
      		ans=min(ans1,ans2);
    }
  	
  	cout<<ans<<endl;
}
    