#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char a[n][m];
	int b[n];
	for(int i=0;i<n;i++){
		b[i]=0;
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
		
	for(int i=0;i<n;i++){
		int t=1;
		for(int j=0;j<m;j++)
			if(a[i][j]=='#')
				t=0;
		if(t==1){
			b[i]=1;
			for(int j=0;j<m;j++)
				a[i][j]='0';
		}
				
	}
	for(int i=0;i<m;i++){
		int t=1;
		for(int j=0;j<n;j++)
			if(a[j][i]=='#')
				t=0;
		if(t==1)
			for(int j=0;j<n;j++)
				a[j][i]='0';	
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if(a[i][j]!='0')
				cout<<a[i][j];	
		if(b[i]==0)cout<<endl;
	}
		
} 