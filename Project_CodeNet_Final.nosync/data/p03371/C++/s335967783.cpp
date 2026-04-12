#include<iostream>
using namespace std;
int main(){
	
	int a,b,c,x,y;
	int tmp,res=0,res2=0,res3=0;
	cin >> a >> b >> c >> x >> y;
		
		if(x>=y)	tmp = y;
		else tmp = x;
		res += c*2*tmp;
		if(x>=y){
			tmp = x-y;
			res+= a*tmp;
			res3 = x*c*2;
		}else{
			tmp = y-x;
			res+= b*tmp;
			res3 = y*c*2;
		}

		res2+=a*x;
		res2+=b*y;
	if(res>res2)	res=res2;
	if(res>res3)	res=res3;
	
	cout << res;
	
	return 0;
}