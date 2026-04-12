#include <iostream>
using namespace std;

int main() {
	int i,j,flag=0;
	int row[101],col[101];
	char a[101][101];

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>i>>j;
	for(int m=1;m<=i;m++){
			cin>>a[m]+1;
	}
	
	for(int m=1;m<=i;m++){
		for(int n=1;n<=j;n++){
			if(a[m][n]=='#'){
			row[m]=-1;
			col[n]=-1;				
			}
		}
	}
	
	for(int m=1;m<=i;m++){
		int flag=0;
		if(row[m]!=-1) continue;
		for(int n=1;n<=j;n++){
			//printf("%c",a[m][n]);
			if(col[n]!=-1) continue;
			cout<<a[m][n];
			flag=1;
		}
		if(flag==1) cout<<"\n";
		//printf("\n");
	}
	

    return 0;
} 
