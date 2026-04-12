#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;


void array_show(int *a,int n){
	for(int i=0;i<n;i++)printf("%d%c",a[i],(i!=n-1?' ':'\n'));
}
void array_show(LL *a,int n){
	for(int i=0;i<n;i++)printf("%lld%c",a[i],(i!=n-1?' ':'\n'));
}

LL dp[3005][3005];
LL t[3005];

int main(){
	int n;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
		dp[i][0]=t[i];
	}
	for(j=1;j<=n;j++){
		for(i=0;i<n;i++){
			if(i+j>=n)break;
			else dp[i][j]=max(t[i]-dp[i+1][j-1],t[i+j]-dp[i][j-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}
