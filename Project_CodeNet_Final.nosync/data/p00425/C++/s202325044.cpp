#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
struct SK{int N;int S;int E;int W;int T;int B;};
void north(struct SK SA);
void south(struct SK SA);
void east(struct SK SA);
void west(struct SK SA);


void right(struct SK SA);
void left(struct SK SA);

int main(){
struct SK SA;
int N;char ch;
int c=0;int k=0;
string SR;

while(1){

scanf("%d",&N);
if(N==0)break;
c=1;k=0;
SA.T=1;
SA.S=2;
SA.B=6;
SA.N=5;
SA.E=3;
SA.W=4;
for(int i=0;i<N;i++)

{
//scanf("%c",&ch);
	cin>>SR;
	if(SR=="North"){int t=0;t=SA.T;SA.T=SA.S;SA.S=SA.B;SA.B=SA.N;SA.N=t;}
//else if(ch=="N")north(SA);
else if(SR=="East"){int t=0;t=SA.T;SA.T=SA.W;SA.W=SA.B;SA.B=SA.E;SA.E=t;}
else if(SR=="West"){int t=0;t=SA.T;SA.T=SA.E;SA.E=SA.B;SA.B=SA.W;SA.W=t;}
else if(SR=="South"){int t=0;t=SA.T;SA.T=SA.N;SA.N=SA.B;SA.B=SA.S;SA.S=t;}
else if(SR=="Right"){int t=0;t=SA.N;SA.N=SA.W;SA.W=SA.S;SA.S=SA.E;SA.E=t;}
else if(SR=="Left"){int t=0;t=SA.N;SA.N=SA.E;SA.E=SA.S;SA.S=SA.W;SA.W=t;}
c+=SA.T;//k++;cout<<SA.T;
}
printf("%d\n",c);
}
return 0;
}

void north(struct SK SA){
int t=0;t=SA.T;SA.T=SA.S;SA.S=SA.B;SA.B=SA.N;SA.N=t;
}
void south(struct SK SA){
int t=0;t=SA.T;SA.T=SA.N;SA.N=SA.B;SA.B=SA.S;SA.S=t;
}
void east(struct SK SA){
int t=0;t=SA.T;SA.T=SA.W;SA.W=SA.B;SA.B=SA.E;SA.E=t;
}
void west(struct SK SA){
int t=0;t=SA.T;SA.T=SA.E;SA.E=SA.B;SA.B=SA.W;SA.W=t;
}


void right(struct SK SA){
int t=0;t=SA.N;SA.N=SA.W;SA.W=SA.S;SA.S=SA.E;SA.E=t;
}
void left(struct SK SA){
int t=0;t=SA.N;SA.N=SA.E;SA.E=SA.S;SA.S=SA.W;SA.W=t;
}