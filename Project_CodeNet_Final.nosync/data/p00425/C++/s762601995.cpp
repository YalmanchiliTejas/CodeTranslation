#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){
	while(1){
		string str;
		int a,buf,N=5,E=3,S=2,W=4,U=1,D=6,answer=0;
		cin>>a;
		if(a==0)return 0;
		for(int i=0;i<a;i++){
			cin>>str;
			if(str=="North"){
				buf=N;
				N=U;
				U=S;
				S=D;
				D=buf;
			}else if(str=="East"){
				buf=E;
				E=U;
				U=W;
				W=D;
				D=buf;
			}else if(str=="West"){
				buf=W;
				W=U;
				U=E;
				E=D;
				D=buf;
			}else if(str=="South"){
				buf=S;
				S=U;
				U=N;
				N=D;
				D=buf;
			}else if(str=="Left"){
				buf=S;
				S=W;
				W=N;
				N=E;
				E=buf;
			}else{
				buf=S;
				S=E;
				E=N;
				N=W;
				W=buf;
			}
			answer+=U;
		}
		printf("%d\n",answer+1);
	}
}