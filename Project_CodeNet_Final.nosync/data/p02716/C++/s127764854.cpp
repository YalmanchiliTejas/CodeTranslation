#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;

int N,K;
ll A[200000],DP[222222][3];
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<222222;i++){
		for(int j=0;j<3;j++){
			DP[i][j]=-1e18;
		}
	}
	DP[0][0]=DP[1][1]=DP[2][2]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			DP[i][j]+=A[i];
			for(int k=0;j+k<3;k++){
				DP[i+2+k][j+k]=max(DP[i+2+k][j+k],DP[i][j]);
			}
		}
	}
	if(N&1){
		cout<<DP[N+1][2]<<endl;
	}
	else{
		cout<<DP[N+1][1]<<endl;
	}
}
