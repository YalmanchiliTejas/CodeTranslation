#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,ab,x,y;
	cin>>a>>b>>ab>>x>>y;
//	int tmp=max(x,y)-min(x,y);
	int tmp=min(x,y),tmp2,tmp3=0;
	int sum=0;
	if(x>y){
		tmp3=x*(ab*2);
	}else{
		tmp3=y*(ab*2);
	}
	if(a+b>ab*2){
		sum+=tmp*(ab*2);
		if(x>y){
			tmp2=x-y;
			sum+=a*tmp2;
		}else if(y>x){
			tmp2=y-x;
			sum+=b*tmp2;
		}else{
		}
	}else{
		sum+=a*x;
		sum+=b*y;
	}
	sum=min(sum,tmp3);
	cout<<sum<<endl;
}
