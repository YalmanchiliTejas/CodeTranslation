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
#include<iomanip>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const LL INF=(LL)1<<50;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

LL t[220000];
LL dp[220000][3];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<3;j++)dp[i][j]=-INF;
	}
	dp[0][0]=t[0],dp[1][1]=t[1],dp[2][2]=t[2];
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			if(dp[i][j]==-INF)continue;
			dp[i+2][j]=max(dp[i+2][j],dp[i][j]+t[i+2]);
			if(j<2)dp[i+3][j+1]=max(dp[i+3][j+1],dp[i][j]+t[i+3]);
			if(j==0)dp[i+4][2]=max(dp[i+4][2],dp[i][0]+t[i+4]);
		}
	}
	LL s;
	if(n%2==1)s=max(max(dp[n-3][0],dp[n-2][1]),dp[n-1][2]);
	else s=max(dp[n-2][0],dp[n-1][1]);
	cout<<s<<endl;
}