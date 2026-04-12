/*
ID: wangjun30
TASK:
LANG: C++
*/
#include<iostream>
using namespace std;
long long num[51],nump[51];
long long dfs(int i,long long x){
	if(x==0)
		return 0;
	if(i==1){
		if(x<5)
			return x-1;
		else
			return x-2;
	}
	long long nege=1,val=0;
	if(x>num[i]/2)
		nege++,val++;
	if(x==num[i])
		nege++;
	if(x>=num[i]/2)
		nege+=num[i-1],val+=nump[i-1];
	x-=nege;
	val+=dfs(i-1,x);
	return val;
}
int main(){
	num[0]=1;
	nump[0]=1;
	for(int i=1;i<=50;i++)
		num[i]=num[i-1]*2+3,nump[i]=nump[i-1]*2+1;
	long long n,x;
	cin>>n>>x;
	cout<<dfs(n,x);
	return 0;
}