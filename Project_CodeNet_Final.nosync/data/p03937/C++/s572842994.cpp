#include<iostream>
using namespace std;
int main(){
	int i,j,k;
	int h,w;
	char a[10][10];
	int m,s=0;
	cin>>h>>w;
	for(i=0;i<h;i++){
		cin>>a[i];
	}
	for(i=0;i<h-1;i++){
		m=0;
		for(j=0;j<w;j++){
			if(a[i][j]=='#' && a[i+1][j]=='#')m++;
		}
		if(m>1)s++;
	}
	for(i=0;i<w-1;i++){
		m=0;
		for(j=0;j<h;j++){
			if(a[j][i]=='#' && a[j][i+1]=='#')m++;
		}
		if(m>1)s++;
	}
	if(s==0){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}