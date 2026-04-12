//============================================================================
// Name        : ATcoder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int N,M;
int D[9][9]={};
int calc(int n1[9],int n2){
	int ans=0;
	int flg=1;
	if(n2>N){
		for(int i=2;i<N+1;++i){
			if(D[n1[i]][n1[i-1]]!=1)flg=0;
		}
		return flg;
	}
	for(int i=2;i<N+1;++i){
		if(n1[i]==0){
			n1[i]=n2;
			ans+=calc(n1,n2+1);
			n1[i]=0;
		}
	}
	return ans;
}

int main() {

	cin>>N>>M;
	int A,B;
	for(int i=0;i<M;++i){
		cin>>A>>B;
		D[A][B]=1;
		D[B][A]=1;
	}

	int n3[9]={};
	n3[1]=1;
	cout<<calc(n3,2)<<endl;


	return 0;
}
