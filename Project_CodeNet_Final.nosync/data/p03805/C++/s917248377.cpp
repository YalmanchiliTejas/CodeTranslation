#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<complex>

using namespace std;

struct res{
	long long int x,y;
};
long long int res=0;

long long int two[80]={1},graph[200][200]={};

void solve(long long int fin[],long long int n,long long int now){
	bool key=true;
	long long int tmp[15];
	for(int i=1;i<=n;i++){
		tmp[i]=fin[i];
	}
	for(int i=1;i<=n;i++){
				
		if(tmp[i]==0){
			key=false;
			tmp[i]=1;
			if(graph[now][i]==1){
			solve(tmp,n,i);
				
			}
			tmp[i]=0;
		}
	}
	if(key){
		res++;
	}
}

const long long int mod=1000000007;
int main(){
	long long int n,m,a[200],b[200],fin[15]={};
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>a[i]>>b[i];
			graph[a[i]][b[i]]=1;
			graph[b[i]][a[i]]=1;
		}
		fin[1]=1;
		solve(fin,n,1);
		cout<<res<<endl;
}
