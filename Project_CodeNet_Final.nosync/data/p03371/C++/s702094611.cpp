#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long a,b,c,numa,numb,numc,more,ans=0;
	cin>>a>>b>>c>>numa>>numb;
	if((a+b)>c*2){  //套装价格便宜
		numc=min(numa,numb)*2;
		if(numa>numb){
			int parta=numa-numb;
			ans=numc*c+parta*a;
		}else{
			int partb=numb-numa;
			ans=numc*c+partb*b;
		}
	}else{           //分开购买便宜
		ans=a*numa+b*numb;
	}
	long long num=max(numb,numa)*2;
	more=num*c;

	cout<<min(ans,more);
	//cout<<endl<<ans<<"  "<<more;
	return 0;
}