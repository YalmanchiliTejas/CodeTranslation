#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<bitset>
#include<queue>
using namespace std;

int main(){
	unsigned long long int a,b,c,x,y,ans=0;
	cin>>a>>b>>c>>x>>y;
	if(2*c<a+b){
		if(x>y){
		  ans = min(c*2*y + a*(x - y),c*2*x);
		}else if(x==y){
			ans = c*2*x;
		}else{
			ans = min(c*2*x + b*(y-x),c*2*y);
		}
	}else{
		ans =x*a+y*b;
	}
	cout<<ans<<endl;
	return 0;
}