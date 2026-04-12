#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long q=0;
long long len[55];
map<int,long long> mp;
long long dfs(int step,long long num)//递归寻找 ,num代表要找的是前num片中有几个'P' 
{
	if(num==1&&step==0) return 1;//如果递归找到第0级就返回1吧 
	if(num==0||num==1) return 0;//如果这个汉堡没有要找的或者只剩皮的话就返回0吧 
	//cout<<"start "<<cc<<":"<<step<<" "<<num<<endl;
	long long sum=0;
	num--;//把最外面的一层包上去的皮去掉 
	long long mid=len[step-1];//折半 
	if(num<mid) return dfs(step-1,num);//如果要找的部分连比他低一级的汉堡都要小，那就直接往下找 
	if(num>=mid) sum+=mp[step-1];//如果能完全覆盖下一级的汉堡，那就直接加上预处理的值 
	num-=len[step-1];//搜索完第一部分了，去掉 
	if(num==0) return sum;//返回 
	sum++;num--;//把中间加上的一片去掉 
	if(num==0) return sum;
	if(num<mid) return dfs(step-1,num)+sum;
	if(num>=mid) sum+=mp[step-1];//同样的办法，就不赘述了 
	return sum;
}
int main()
{
	len[0]=1;
	for(int i=1;i<=50;i++) len[i]=len[i-1]*2+3;//记录每级汉堡有几层 
	mp[0]=1;
	for(int i=1;i<=50;i++) mp[i]=mp[i-1]*2+1;//记录每层汉堡有几个'P' 
	cin>>n>>k;
	cout<<dfs(n,k);
}