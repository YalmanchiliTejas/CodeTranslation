#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <string.h>
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0)break;
		int ans=1,temp;
		int saikoro[6]={1,2,3,4,5,6};
		string dir;
		for(int i=0;i<n;i++){
			cin>>dir;
			if(dir=="North"){
				temp=saikoro[0];
				saikoro[0]=saikoro[1];
				saikoro[1]=saikoro[5];
				saikoro[5]=saikoro[4];
				saikoro[4]=temp;
			}
			if(dir=="East"){
				temp=saikoro[0];
				saikoro[0]=saikoro[3];
				saikoro[3]=saikoro[5];
				saikoro[5]=saikoro[2];
				saikoro[2]=temp;
			}
			if(dir=="South"){
				temp=saikoro[0];
				saikoro[0]=saikoro[4];
				saikoro[4]=saikoro[5];
				saikoro[5]=saikoro[1];
				saikoro[1]=temp;
			}
			if(dir=="West"){
				temp=saikoro[0];
				saikoro[0]=saikoro[2];
				saikoro[2]=saikoro[5];
				saikoro[5]=saikoro[3];
				saikoro[3]=temp;
			}
			if(dir=="Right"){
				temp=saikoro[1];
				saikoro[1]=saikoro[2];
				saikoro[2]=saikoro[4];
				saikoro[4]=saikoro[3];
				saikoro[3]=temp;
			}
			if(dir=="Left"){
				temp=saikoro[1];
				saikoro[1]=saikoro[3];
				saikoro[3]=saikoro[4];
				saikoro[4]=saikoro[2];
				saikoro[2]=temp;
			}
			ans+=saikoro[0];
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}