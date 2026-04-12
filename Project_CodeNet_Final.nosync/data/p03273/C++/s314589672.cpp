#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w,n,m;
	n=m=0;
	cin>>h>>w;
	char a[h][w];
	for(int i=0;i<h;i++){
		cin>>a[i];
	}
		n=m;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(a[i][j]=='#')break;
				if(j==w-1){
					for(int j=0;j<w;j++){
						a[i][j]='0';
					}
					m++;
				}
			}
		}
		for(int j=0;j<w;j++){
			for(int i=0;i<h;i++){
				if(a[i][j]=='#')break;
				if(i==h-1){
					for(int i=0;i<h;i++){
						a[i][j]='0';
					}
					m++;
				}
			}
		}
	int x;
	x=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j]!='0')cout<<a[i][j];
			if(a[i][j]=='0')x++;
		}
		if(x!=w)cout<<endl;
		x=0;
	}
}