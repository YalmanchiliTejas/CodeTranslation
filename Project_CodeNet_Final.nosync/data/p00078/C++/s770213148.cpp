#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	int a[20][20];
	cin>>n;
	while(n!=0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				a[i][j]=0;
			}
		}
		int k=1+n/2;
		int l=n/2;
		int m=1;
a[k][l]=1;
		for(int u=0;u<n;u++){
			for(int v=1;v<n;v++){
			
			k=(k+1)%n;
			l=(l+1)%n;
			m=m+1;
			a[k][l]=m;
			}
			k=(k+2)%n;
			m=m+1;
			a[k][l]=m;
		}
		a[k][l]=a[k][l]-n*n;
		for(int q=0;q<n;q++){
			for(int w=0;w<n;w++){
				if(10>a[q][w]){
				cout<<"   "<<a[q][w];
				}
				else if(100>a[q][w]){
					cout<<"  "<<a[q][w];
				}
				else if(99<a[q][w]){
					cout<<" "<<a[q][w];
				}
			}
			cout<<endl;
		}
		
		
		cin>>n;
	}
	return 0;
}