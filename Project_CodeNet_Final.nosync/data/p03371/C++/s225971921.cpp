#include <iostream>
using namespace std;
int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int pt1,pt2,pt3;
	pt1=a*x+b*y;
	pt2=(x>y?y:x)*2*c;
	pt3=(x>y?x:y)*2*c;
	if(x>y){
		pt2+=(x-y)*a;
	}else{
		pt2+=(y-x)*b;
	}
	printf("%d\n",(pt1>pt2)?(pt2>pt3?pt3:pt2):(pt1>pt3?pt3:pt1));
}
