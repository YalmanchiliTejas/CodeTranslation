#include <iostream>
using namespace std;
int main(){
	int a,b,c,x,y,tmpx,tmpy;
	long total=0,subtotal=0;
	cin>>a>>b>>c>>x>>y;
	tmpx=x;
	tmpx=y;
	if ((a+b)/2>=c){
		if (tmpx%2==1)	tmpx-=1;
		if (tmpy%2==1)	tmpy-=1;
		int min=(x>y)?y:x;
		total+=min*2*c;
		if (x>min)	total+=(x-min)*a;
		if (y>min)	total+=(y-min)*b;
		
		int max=(x>y)?x:y;
		subtotal=max*c*2;
	}
	else{
		total+=x*a+y*b;
	}
	if (subtotal>total || subtotal==0)	cout<<total;
	else	cout<<subtotal;
	return 0;
}