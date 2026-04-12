#include<iostream>
using namespace std;

int main()
{
	int h,w;
	cin>>h>>w;
	char a[100][100];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++) cin>>a[i][j];
	}
	
	bool fh[100]={0},fw[100]={0};
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){ 
			if(a[i][j]=='#'){
				fh[i]=1;
				fw[j]=1;
			}
		}
	}
	
	for(int i=0;i<h;i++){
		if(fh[i]==0) continue;
		for(int j=0;j<w;j++){
			if(fw[j]==0) continue;
			cout<<a[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}
