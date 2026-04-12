#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<set>
using namespace std;
int ta[100][100];
int main(){
	int n;
	while(
	cin>>n,n){
	int ni=(n+1)/2+1;
	int nj=(n+1)/2;
	
	for(int i=0;i<100;i++)for(int j=0;j<100;j++)ta[i][j]=-1;
	ta[ni][nj]=1;
	int now=2;
	for(int i=1;i<n*n;i++){
			ni++;nj++;
				while(true){
				if(nj>n)nj=1;
				if(nj<1)nj=n;
				if(ni>n)ni=1;
					if(ta[ni][nj]!=-1){
						ni++,nj--;
					}
					if(ni>=1&&ni<=n&&nj>=1&&nj<=n&&ta[ni][nj]==-1)break;
				}

			ta[ni][nj]=now;
			now++;
	}
	
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){printf("%4d",ta[i][j]);}
	cout<<endl;
	}
	
	}
	return 0;
}