#include <iostream>
#define LEFT 0
using namespace std;

int N;
long long int DP[3001][3001]={};
long long int a[3001]={};

long long int solve(int l,int r,int turn){
	if(l>r) return 0;
	if(DP[l][r]) return DP[l][r];
	long long int ret=0;
	
	if(!turn){
		ret=max(a[l]+solve(l+1,r,turn^1),a[r]+solve(l,r-1,turn^1));
	}else{
		ret=min(solve(l+1,r,turn^1)-a[l],solve(l,r-1,turn^1)-a[r]);
	}
	
//	printf("DP[%d][%d]=%d\n",l,r,ret);
	return DP[l][r]=ret;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>a[i];
	cout<<solve(0,N-1,0)<<"\n";
	return 0;
}