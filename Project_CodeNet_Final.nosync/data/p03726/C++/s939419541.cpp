#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int>v[maxn];
int dp[maxn];
bool mark;
bool marv[maxn];
int h[maxn];
void ok_h(int v1,int par){
	marv[v1]=true;
	for(int i=0;i<v[v1].size();i++){
		if(marv[v[v1][i]]==false){
			h[v[v1][i]]=h[v1]+1;
			ok_h(v[v1][i],v1);
		}
	}
}
void dfs(int v1,int par){
	int cnt=0;
	int cnv=0;
	marv[v1]=true;
	for(int i=0;i<v[v1].size();i++){
		if(marv[v[v1][i]]==false&&h[v[v1][i]]>h[v1]){
			dfs(v[v1][i],v1);
		}
		if(dp[v[v1][i]]==1&&h[v[v1][i]]>h[v1]){
			cnt++;
		}
		else if(h[v[v1][i]]>h[v1]){
			cnv++;
		}
	}
	if(v1==1){
		if(cnt>=1&&cnv==0){
			mark=true;
		}
	}
	if(cnv>=2){
		mark=true;
	}
	if(v[v1].size()==1&&v1!=1){
		dp[v1]=0;
	}
	else if(cnv==1){
		dp[v1]=1;
	}
	else{
		dp[v1]=0;
	}
//	cout<<v1<<" "<<dp[v1]<<" "<<cnv<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(false);cout.tie(false);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a;
		int b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	h[1]=1;
	ok_h(1,-1);
	fill(marv,marv+maxn,0);
	dfs(1,-1);
	if(mark==true){
		cout<<"First";
	}
	else{
		cout<<"Second";
	}
}