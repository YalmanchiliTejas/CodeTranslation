#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M;cin>>N>>M;
	int edge[N][N]={0};
	int a,b;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            edge[i][j]=0;
        }
    }for(int i=0;i<M;i++){
		cin>>a>>b;
		edge[a-1][b-1]=1;
		edge[b-1][a-1]=1;
	}vector<int> v(N);
	iota(v.begin(),v.end(),0);
    int calculate=0;bool possible;
	do{
		possible=true;
		for(int j=1;j<N;j++){
			if(edge[v[j-1]][v[j]]==0){
				possible=false;
			}
		}if(possible==true){
			calculate++;
		}
	}while(next_permutation(v.begin()+1,v.end()));
	cout<<calculate<<endl;
}