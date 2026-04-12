#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,k[6];
	string a;
	while(true){
	cin>>n;
	if(n==0)
		break;
	for(int i=0;i<6;i++)
		k[i]=i+1;
	int count=1;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a=="North"){
			int tmp=k[0];
			k[0]=k[1];
			k[1]=k[5];
			k[5]=k[4];
			k[4]=tmp;
		}
		if(a=="East"){
			int tmp=k[0];
			k[0]=k[3];
			k[3]=k[5];
			k[5]=k[2];
			k[2]=tmp;
		}
		if(a=="West"){
			int tmp=k[0];
			k[0]=k[2];
			k[2]=k[5];
			k[5]=k[3];
			k[3]=tmp;
		}
		if(a=="South"){
			int tmp=k[0];
			k[0]=k[4];
			k[4]=k[5];
			k[5]=k[1];
			k[1]=tmp;
		}
		if(a=="Right"){
			int tmp=k[1];
			k[1]=k[2];
			k[2]=k[4];
			k[4]=k[3];
			k[3]=tmp;
		}
		if(a=="Left"){
			int tmp=k[1];
			k[1]=k[3];
			k[3]=k[4];
			k[4]=k[2];
			k[2]=tmp;
		}
		count+=k[0];
	}
	cout<<count<<endl;
	}
	return 0;
}