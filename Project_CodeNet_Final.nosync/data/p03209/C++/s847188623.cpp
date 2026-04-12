#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long q=0;
long long len[55];
map<int,long long> mp;
long long dfs(int step,long long num)
{
	if(num==1&&step==0) return 1;
	if(num==0||num==1) return 0;
	//cout<<"start "<<cc<<":"<<step<<" "<<num<<endl;
	long long sum=0;
	num--;
	long long mid=len[step-1];
	if(step==0) return 1;
	if(num<mid) return dfs(step-1,num);
	if(num>=mid) sum+=mp[step-1];
	num-=len[step-1];
	if(num==0) return sum;
	if(num!=0) sum++;
	num--;
	if(num==0) return sum;
	if(num<mid) return dfs(step-1,num)+sum;
	if(num>=mid) sum+=mp[step-1];
	return sum;
}
int main()
{
	len[0]=1;
	for(int i=1;i<=50;i++) len[i]=len[i-1]*2+3;
	mp[0]=1;
	for(int i=1;i<=50;i++) mp[i]=mp[i-1]*2+1;
	mp[0]=1;
	cin>>n>>k;
	cout<<dfs(n,k);
}