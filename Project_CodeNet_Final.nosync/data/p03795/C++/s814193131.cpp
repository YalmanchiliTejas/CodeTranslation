#include<iostream>
using namespace std;
int main()
{
	int a,n;
	cin>>n;   //输入n 
	a=n/15;   //算出小紫可以优惠几次 
	cout<<800*n-a*200<<endl;//用菜的总价减去优惠的价格得到优惠后的金额 
	return 0;
}