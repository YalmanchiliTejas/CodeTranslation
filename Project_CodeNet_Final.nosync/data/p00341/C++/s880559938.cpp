#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int main(){
	int e[12],lon1,lon2,lon3,sum1=0,sum2=0,sum3=0;
	for(int i=0;i<12;i++){
		cin>>e[i];
	}
	sort(e,e+12);
	lon1=e[0];
	lon2=e[4];
	lon3=e[8];
	for(int j=0;j<4;j++){
		sum1+=e[j];
		sum2+=e[j+4];
		sum3+=e[j+8];
	}
	if(e[0]*4==sum1 && e[4]*4==sum2 && e[8]*4==sum3){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
	return 0;
}