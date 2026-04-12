#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;

int main(){
	int N,M;
	cin>>N>>M;
	int G[10][10];
	rep1(i,N)rep1(j,N)G[i][j]=0;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a][b]=1;
		G[b][a]=1;
	}
	int p[10];
	rep(i,N-1)p[i]=i;
	int ans=0;
	do{
		int path=1;
		path*=G[1][p[0]+2];
		rep1(i,N-2)path*=G[p[i-1]+2][p[i]+2];
		ans+=path;
	}while(next_permutation(p,p+(N-1)));
	cout<<ans;
}