#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long a,b,c,numa,numb,numc,more=0x7fffffffff,ans=0;
	cin>>a>>b>>c>>numa>>numb;
	if((a+b)>c*2){  //套装价格便宜
		long long num=max(numb,numa)*2;
		more=num*c;
		numc=min(numa,numb)*2;
		if(numa>numb){
			numa-=numb;
			ans=numc*c+numa*a;
		}else{
			numb-=numa;
			ans=numc*c+numb*b;
		}
	}else{           //分开购买便宜
		ans=a*numa+b*numb;
	}
	cout<<min(ans,more);
	return 0;
}
