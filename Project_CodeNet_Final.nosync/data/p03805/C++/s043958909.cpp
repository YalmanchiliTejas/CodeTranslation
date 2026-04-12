#include <bits/stdc++.h>
using namespace std;
#define r(i,a,n) for(int i=a;i<n;i++)
int a[9][9],n,v[9][9];
int dfs(int s,int d){
	int ss=0;
	if(d==n-1)return 1;
	r(i,1,n+1){
		r(j,1,n+1)v[j][s]=1;
		if(a[s][i]&&!v[s][i])ss+=dfs(i,d+1);
		r(j,1,n+1)v[j][s]=0;
	}
	return ss;
}
int main(){
	int m,qq,ww,s;
	cin>>n>>m;
	r(i,0,m){
		cin>>qq>>ww;
		a[qq][ww]=1;
		a[ww][qq]=1;
	}
	r(i,1,n+1){
		r(j,0,n+1)r(k,0,n+1)v[i][j]=0;
		if(a[1][i]){
			r(k,1,n+1)v[k][1]=1;
			s+=dfs(i,1);		}
	}
	cout<<s<<endl;
}