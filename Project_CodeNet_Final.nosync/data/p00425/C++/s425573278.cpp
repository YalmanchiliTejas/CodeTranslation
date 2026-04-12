#include<iostream>
#include<string>
using namespace std;

int x[6];
int n,c;string S;

int hantei(){
	int A,B,C,D;
	if(S=="North"){
		A=x[0];
		B=x[1];
		C=x[5];
		D=x[4];
		x[0]=B;
		x[1]=C;
		x[5]=D;
		x[4]=A;
	}
	if(S=="South"){
		A=x[0];
		B=x[1];
		C=x[5];
		D=x[4];
		x[0]=D;
		x[1]=A;
		x[5]=B;
		x[4]=C;
	}
	if(S=="East"){
		A=x[0];
		B=x[2];
		C=x[5];
		D=x[3];
		x[0]=D;
		x[2]=A;
		x[5]=B;
		x[3]=C;
	}
	if(S=="West"){
		A=x[0];
		B=x[2];
		C=x[5];
		D=x[3];
		x[0]=B;
		x[2]=C;
		x[5]=D;
		x[3]=A;
	}
	if(S=="Left"){
		A=x[1];
		B=x[2];
		C=x[4];
		D=x[3];
		x[1]=D;
		x[2]=A;
		x[4]=B;
		x[3]=C;
	}
	if(S=="Right"){
		A=x[1];
		B=x[2];
		C=x[4];
		D=x[3];
		x[1]=B;
		x[2]=C;
		x[4]=D;
		x[3]=A;
	}
	return x[0];
}

int main(){
	while(true){
		cin>>n;
		if(n==0){break;}
		x[0]=1;x[1]=2;x[2]=3;x[3]=4;x[4]=5;x[5]=6;c=1;
		for(int i=0;i<n;i++){
			cin>>S;
			c+=hantei();
		}
		cout<<c<<endl;
	}
}