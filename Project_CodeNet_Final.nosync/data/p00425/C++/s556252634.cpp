#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int ue,migi,mae;
int main(){
	int N;
	string str;
	int strsn[10000];
	int tokitasu,tmp;
	while(1){
	cin>>N;
	if(N==0)  break;
	for(int i=0;i<N;i++){
		cin>>str;
		if(str=="North")strsn[i]=0;
		else if(str=="East")strsn[i]=1;
		else if(str=="South")strsn[i]=2;
		else if(str=="West")strsn[i]=3;
		else if(str=="Right")strsn[i]=4;
		else strsn[i]=5;
	}
	tokitasu=1;
	ue=1;migi=3;mae=2;
	for(int i=0;i<N;i++){
		switch(strsn[i]){
		case 0:
			tmp=ue;
			ue=mae;
			mae=(7-tmp);
			break;
		case 1:
			tmp=ue;
			ue=(7-migi);
			migi=tmp;
			break;
		case 3:
			tmp=ue;
			ue=migi;
			migi=(7-tmp);
			break;
		case 2:
			tmp=ue;
			ue=(7-mae);
			mae=tmp;
			break;
		case 4:
			tmp=mae;
			mae=migi;
			migi=(7-tmp);
			break;
		case 5:
			tmp=mae;
			mae=(7-migi);
			migi=tmp;
			break;
		}
		tokitasu+=ue;
	}
	cout<<tokitasu<<endl;
	}
	return 0;
}