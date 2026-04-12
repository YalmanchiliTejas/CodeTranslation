#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int sq[15][15]={0};
		if(n==0)break;
		for(int i=n/2+1,j=n/2,count=1;count!=n*n+1;){
			if(sq[i][j]){
				i=(i+1)%n;
				j=((j-1)+n)%n;
				sq[i][j]=count;
			}else{
				sq[i][j]=count;
			}
			i=(i+1)%n;
			j=(j+1)%n;
			++count;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)printf("%4d",sq[i][j]);
			printf("\n");
		}
	}
	return 0;
}