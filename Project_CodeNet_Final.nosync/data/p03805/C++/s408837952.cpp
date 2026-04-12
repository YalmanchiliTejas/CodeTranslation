#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

bool flag[50],pass[50][50];
int n,m;

int dfs(int now,int depth){	//now: 開始頂点;
	if(flag[now])return 0;	
	if(depth==n)return 1;	//底まで探索でansを+1;
	flag[now]=true;			//訪問した頂点の履歴;
	int ans=0;	
	for(int i=0;i<n;i++)
		if(pass[now][i])ans+=dfs(i,depth+1); //深さを+1し探索;
	flag[now]=false;		//履歴の消去;
	return ans;
}

int main(){
	int a[55],b[55];

	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
		pass[a[i]][b[i]]=pass[b[i]][a[i]]=true;
	}
	cout<<dfs(0,1)<<endl;

}