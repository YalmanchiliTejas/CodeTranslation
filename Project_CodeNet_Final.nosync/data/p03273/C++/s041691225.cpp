#include<bits/stdc++.h>
using namespace std;
int main(void){
	 char a[101][101];
	 int h,w;
	 int i,j,k;
	 cin>>h>>w;
	 for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			 cin>>a[i][j];
		}
	 }
	 
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(a[i][j]=='#'){
				break;
			}
		}
		if(j==w){
			for(j=0;j<w;j++){
				a[i][j]='*';
			}
		}
	}
	for(j=0;j<w;j++){
		for(i=0;i<h;i++){
			if(a[i][j]=='#'){
				break;
			}
		}
		if(i==h){
			for(i=0;i<h;i++){
				a[i][j]='*';
			}
		}
	}
	/*for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	cout<<endl;*/
	for(i=0;i<h;i++){
		int flg=0;
		for(j=0;j<w;j++){
			if(a[i][j]=='*')	continue;
			cout<<a[i][j];
		}
		for(j=0;j<w;j++){
			if(a[i][j]!='*'){
				break;
			}
		}
		if(j==w)	flg=1;
		if(flg==0)cout<<endl;
	}
	return 0;
}
				
				