#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int main(){
	int a,b,c,x,y,ans=0;
	cin>>a>>b>>c>>x>>y;
	if(c*2<a+b){
		int sma=min(x,y);
		ans+=sma*c*2;
		x-=sma;
		y-=sma;
		int big=max(x,y);
		int yen=0;
		if(x){
			yen=a;
		}else{
			yen=b;
		}
		if(c*2<yen){
			ans+=big*c*2;
		}else{
			ans+=big*yen;
		}
		cout<<ans<<endl;
		return 0;
	}else{
		ans+=x*a;
		ans+=y*b;
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}