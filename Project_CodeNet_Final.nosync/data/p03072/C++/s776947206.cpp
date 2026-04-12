#include<iostream>
using namespace std;
int main()
{
	int N,count=1,k;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	k=A[0];
	for(int i=0;i<N-1;i++){
		if(A[i+1]>=k){
			k=A[i+1];  
			count=count+1;
		}
	}
	cout<<count<<endl;
}