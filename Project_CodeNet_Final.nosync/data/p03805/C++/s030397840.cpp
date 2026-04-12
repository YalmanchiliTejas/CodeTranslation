#include <bits/stdc++.h>
using namespace std;

int main (){
	int N,M,path[100][100];
	cin>>N>>M;

	for(int t=0;t<100;t++){
		for(int j=0;j<100;j++){
			path[t][j]=0;
		}
	}
	for(int t=0;t<M;t++){
		int a,b;
		cin>>a>>b;
		path[a][b]=path[b][a]=1;
	}

	int cont=0;
	vector<int>v(N-1);
	iota(v.begin(),v.end(),2);

	do{
		bool flag=true;
		if(path[1][v[0]]==0)continue;
		for(int t=0;t<N-2;t++){
			if(path[v[t]][v[t+1]]==0){
				flag=false;
				break;
			}
		}
		if(flag)cont++;

	}while(next_permutation(v.begin(),v.end()));

	cout<<cont<<"\n";
	return 0;
}

