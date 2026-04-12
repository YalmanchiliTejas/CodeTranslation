#include <iostream>
using namespace std;
int main(){
	int n,x,y;
	scanf("%d",&n);
	x=800*n;//合計金額
	y= (n/15)*200;
	printf("%d",x-y);
	return 0;
}