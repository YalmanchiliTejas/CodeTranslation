#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		int num=n*n,m,l;
		int hyou[16][16]={0};
		m=(n/2)+1;
		l=m+1;
		hyou[l][m]=1;
		for(int i=2;i<=num;i++){
			m++,l++;
			if(m>n || l>n)if(m>n)m=1;if(l>n)l=1;

			if(hyou[l][m]==0){
				hyou[l][m]=i;
			}else{
				m-=1;
				if(m==0)m=n;
				l+=1;
				if(l>n)if(l==n+1)l=1;else l=2;
				
				hyou[l][m]=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%4d",hyou[i][j]);
			}
			cout<<endl;
		}
	}
	return 0;
}