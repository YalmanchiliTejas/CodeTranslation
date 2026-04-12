#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) FOR((i),0,(n))

typedef long long ll;

const int INF=1e9+7;
int G[9][9];
int tmp[8];
int main(){
	int n,m;
	cin>>n>>m;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		G[a][b]=G[b][a]=1;
	}
	rep(i,8)tmp[i]=i+1;
	int ans=0;
	do{
		bool f=true;
		rep(i,n-1)f&=G[tmp[i]][tmp[i+1]];
		if(f)ans++;
	}while(next_permutation(tmp+1,tmp+n));
	cout<<ans<<endl;
}
