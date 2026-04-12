#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll dfs(vector<ll> A,vector<ll> P,ll N,ll X){
	ll res=0;
	if(N==1){
		if(X==2) res+=1;
		if(X==3) res+=2;
		if(X==4) res+=3;
		if(X==5) res+=3;
		return res;
	}
	if(X==1){
		res+=0;
	}else if(2<=X && X<=A[N-1]+1){
		res+=dfs(A,P,N-1,X-1);
	}else if(X==A[N-1]+2){
		res+=1+P[N-1];
	}else if(3+A[N-1]<=X && X<=2*A[N-1]+2){
		res+=P[N-1]+1+dfs(A,P,N-1,X-(2+A[N-1]));
	}else{
		res+=P[N];
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	ll N,X;
	cin>>N>>X;
	vector<ll> A(N+1);
	vector<ll> P(N+1);
	for(int i=1;i<=N;i++){
		if(i==1){
			A[i]=5;
			P[i]=3;
		}else{
			A[i]=A[i-1]*2+3;
			P[i]=P[i-1]*2+1;
		}
	}
	cout<<dfs(A,P,N,X)<<endl;
	return 0;
}