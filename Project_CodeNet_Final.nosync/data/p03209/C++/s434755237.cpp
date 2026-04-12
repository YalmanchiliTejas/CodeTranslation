#include<bits/stdc++.h>
#define llint long long int
using namespace std;
llint n,k;
llint len[51],full[51];

llint f(llint n, llint k)
{
	if(k<=0)return 0;
	if(n<=0)return 1;
llint ret=0;
	if(k>len[n]/2)
 return full[n-1]+1+f(n-1,k-len[n]/2-1);
 else return f(n-1,k-1); 
}

int main(void)
{
	len[0]=1;
	for(int i=1;i<51;i++) len[i]=len[i-1]*2+3;
	full[0]=1;
	for(int i=1;i<51;i++) full[i]=full[i-1]*2+1;
	cin>>n>>k;
	cout<<f(n,k)<<endl;
	return 0;
}