#include<iostream>
#include<string>
using namespace std;
int a[6]={1,2,3,4,5,6},b[6];
int main(){
	while(true){
		a[0]=1;a[1]=2;a[2]=3;a[3]=4;a[4]=5;a[5]=6;
		int n;cin>>n;int cnt=1;if(n==0)break;
		for(int i=0;i<n;i++){
			string S;cin>>S;
			for(int i=0;i<6;i++)b[i]=a[i];
			if(S=="North"){a[0]=b[1];a[1]=b[5];a[2]=b[2];a[3]=b[3];a[4]=b[0];a[5]=b[4];}
			if(S=="South"){a[0]=b[4];a[1]=b[0];a[2]=b[2];a[3]=b[3];a[4]=b[5];a[5]=b[1];}
			if(S=="East"){a[0]=b[3];a[1]=b[1];a[2]=b[0];a[3]=b[5];a[4]=b[4];a[5]=b[2];}
			if(S=="West"){a[0]=b[2];a[1]=b[1];a[2]=b[5];a[3]=b[0];a[4]=b[4];a[5]=b[3];}
			if(S=="Right"){a[0]=b[0];a[1]=b[2];a[2]=b[4];a[3]=b[1];a[4]=b[3];a[5]=b[5];}
			if(S=="Left"){a[0]=b[0];a[1]=b[3];a[2]=b[1];a[3]=b[4];a[4]=b[2];a[5]=b[5];}
			cnt+=a[0];
		}
		cout<<cnt<<endl;
	}
	return 0;
}