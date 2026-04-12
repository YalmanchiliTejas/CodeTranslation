#include <iostream>
using namespace std;
int d[6]={1,2,3,5,4,6};

void change_post(int a,int b,int c,int dd,int e,int f){
	d[0]=a; d[1]=b; d[2]=c; d[3]=dd; d[4]=e; d[5]=f;
}

int main(void){
	string s;
	int k,n,sum;
	while(1){
		sum=1;
		change_post(1,2,3,5,4,6);
		cin>>n;
		if(!n) return 0;
		while(n--){
			cin>>s;
			if(s=="North") change_post(d[1],d[5],d[2],d[0],d[4],d[3]);
			else if(s=="East") change_post(d[4],d[1],d[0],d[3],d[5],d[2]);
			else if(s=="West") change_post(d[2],d[1],d[5],d[3],d[0],d[4]);
			else if(s=="South") change_post(d[3],d[0],d[2],d[5],d[4],d[1]);
			else if(s=="Right") change_post(d[0],d[2],d[3],d[4],d[1],d[5]);
			else change_post(d[0],d[4],d[1],d[2],d[3],d[5]);
			sum+=d[0];
		}
		cout<<sum<<endl;
	}
}

	