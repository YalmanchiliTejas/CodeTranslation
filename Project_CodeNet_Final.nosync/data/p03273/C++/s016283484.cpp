#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{
	int i,j,k,h,w,cnt1,cnt2;
	char a[101][101];
	cnt1=0;
	cnt2=0;
	cin>>h>>w;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cin>>a[i][j];
		}
	}
	
	for(i=0;i<h;i++){
//		cout<<"-----------"<<endl;
		for(j=0;j<w;j++){
			if(a[i][j]=='.'){
				cnt1=cnt1+1;
//				cout<<cnt1<<' '<<a[i][j]<<endl;
			}
		}
		if(cnt1==w){
			if(i==h){
				h=h-1;
			}
			else{
				for(j=i;j<h;j++){
					for(k=0;k<w;k++){
						swap(a[j][k],a[j+1][k]);
					}
				}
				h=h-1;
//				cout<<cnt1<<' '<<h<<endl;
			}
			i=i-1;
		}
		cnt1=0;
		
	/*	for(j=0;j<h;j++){
			for(k=0;k<w;k++){
				cout<<a[j][k];
			}
			cout<<endl;
		}*/
//		cout<<"-----------"<<endl;
	}
	
//	cout<<"+++++++++++++++++++++++"<<endl;
	
	for(i=0;i<w;i++){
//		cout<<"-----------"<<endl;
		for(j=0;j<h;j++){
			if(a[j][i]=='.'){
				cnt2=cnt2+1;
//				cout<<i<<j<<cnt2<<' '<<a[j][i]<<endl;
			}
		}
		if(cnt2==h){
			if(i==w){
				w=w-1;
			}
			else{
				for(j=i;j<w;j++){
					for(k=0;k<h;k++){
						swap(a[k][j],a[k][j+1]);
					}
				}
				w=w-1;
//				cout<<cnt2<<' '<<w<<endl;
			}
			i=i-1;
		}
		cnt2=0;
		
	/*	for(j=0;j<h;j++){
			for(k=0;k<w;k++){
				cout<<a[j][k];
			}
			cout<<endl;
		}*/
//		cout<<"-----------"<<endl;
	}
	
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}
