#include<iostream>
using namespace std;
const int MAX = 200001;
int main(){
	int N,A[MAX];
	long long int sum[MAX][3],ans=0;
	bool visit[MAX][3]={0};
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N-N%2;i+=2)ans+=A[i];
	
	if(N%2){
		sum[0][2]=A[0];visit[0][2]=true;
		sum[1][1]=A[1];visit[1][1]=true;
		sum[2][0]=A[2];visit[2][0]=true;
		if(N==3)ans=max(A[0],max(A[1],A[2]));
	}else{
		sum[0][1]=A[0];visit[0][1]=true;
		sum[1][0]=A[1];visit[1][0]=true;
		if(N==2)ans=max(A[0],A[1]);
	}
	
	for(int i=0;i+2<N;i++)for(int j=0;j<3;j++){
		if(!visit[i][j])continue;
		for(int k=0;k<=min(j,N-i-3);k++){
			if(visit[i+2+k][j-k])sum[i+2+k][j-k]=max(sum[i+2+k][j-k],sum[i][j]+A[i+2+k]);
			else sum[i+2+k][j-k]=sum[i][j]+A[i+2+k];
			visit[i+2+k][j-k]=true;
			if(i+2+k>=N-(j-k+1))ans=max(ans,sum[i+2+k][j-k]);
		}
	}
	cout<<ans;
	return 0;
}