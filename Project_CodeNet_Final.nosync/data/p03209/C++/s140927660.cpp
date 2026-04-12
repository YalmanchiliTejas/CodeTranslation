#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main()
{
  	ull a[51][2],x,y=0;//二维数组第0列存储总的layers数，第1列 存储总的P的个数，x从bottom开始
	  //的层数，y为在x层中有y个P 
	int n,i,j;;//n为总的level数
	cin>>n>>x;
	a[0][0]=1,a[0][1]=1;// level-0的总layers数和总P数均为1
	for(i=1;i<=n;i++)
	{
		a[i][0]=2*a[i-1][0]+3;//根据计算规则得出第i层与第i-1层的layers数之间的关系 
		a[i][1]=2*a[i-1][1]+1;//根据计算规则得出第i层与第i-1层的P数之间的关系 
	} 
	//计算x中的P总数y
	while(x>0) //x=0的话就不存在P的数量
	{
		//A level-L burger (L≥1) is a bun, a level-(L-1) burger, a patty, 
  		//another level-(L-1) burger and another bun
  		if(x==a[n][0]) 
		{
			y+=a[n][1];
			x=0;
		}
  		else if(x>=a[n][0]/2+1)
  		{
  			y+=a[n-1][1]+1;
  			x-=a[n][0]/2+1;
		} 
		else x--;//相当于将总数-1，即将B去掉1 
		//做完以上事情后需要将n减1
		n--; 
	} 
	cout<<y<<endl;
	return 0;
}

