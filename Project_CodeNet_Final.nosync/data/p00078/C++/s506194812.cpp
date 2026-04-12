#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <vector<int> > A;
int magic(int n){
	int c=1,x=n/2,y=x+1;
	while (c<=n*n){
		if (A[y][x]==0){
			A[y][x]=c++;
			x++;
		}
		else x+=n-1;
		y+=n+1;
		x%=n;
		y%=n;
	}
	return 0;
}
int main(){
	int n,i,j;
	while(cin>>n,n!=0){
		A.resize(n);
		for(i=0;i<n;i++)A[i].resize(n,0);
		magic(n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)printf("%4d",A[i][j]);
			cout<<endl;
		}
		A.clear();
	}
}