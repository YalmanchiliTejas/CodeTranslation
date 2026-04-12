#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<cstring>
using namespace std;


int main(){
	
	char ql[]={"qwertasdfgzxcvb"},qr[]={"yuiophjklnm"};
	while(1){
		int n,i,j,k,x=1,sum=0;
		char a[33];
		cin>>a;
		if(a[0]=='#')break;
		n=strlen(a);
		for(i=0;i<strlen(ql);i++){
			if(ql[i]==a[0]){x=0;break;}
		}
		for(i=1;i<n;i++){
			if(x==0){
				for(j=0;j<strlen(qr);j++){
					if(qr[j]==a[i]){
						sum++;x=1;break;
					}
				}
			}else{
				for(j=0;j<strlen(ql);j++){
					if(ql[j]==a[i]){
						sum++;x=0;break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
    return 0;
}