#include<iostream>
#include<vector>
using namespace std;
void search(int p,vector<int>e,vector<int> foot,int*sum){
	foot[p]=1;
	int flag=0;
	for(int i=0;i<foot.size();i++){
		if(foot[i]==0) flag=1;
	}
	if(flag==0){
		*sum+=1;
		foot[p]=0;
		return;
	}
	for(int i=0;i<foot.size();i++){
		if(e[p*foot.size()+i]==1&&foot[i]==0){
			search(i,e,foot,sum);
		}
	}
	foot[p]=0;
	return;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> e(n*n,0);
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--;
		b--;
		e[a*n+b]=1;
		e[b*n+a]=1;
	}
	vector<int> foot(n,0);
	int sum=0;
	search(0,e,foot,&sum);
	cout<<sum<<endl;
	return 0;
}