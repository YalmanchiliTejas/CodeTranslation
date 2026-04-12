#include<bits/stdc++.h>
using namespace std;

int main(){
	int e[12];	for(int i=0;i<12;i++)cin>>e[i];
	sort(e,e+12);

	bool flag=true;

	for(int i=0;i<4;i++){
		if(e[0]!=e[i]){
			flag=false;
			break;
		}
	}

	if(flag){
		for(int i=0;i<4;i++){
			if(e[4]!=e[4+i]){
				flag=false;
				break;
			}
		}
	}

	if(flag){
		for(int i=0;i<4;i++){
			if(e[8]!=e[8+i]){
				flag=false;
				break;
			}
		}
	}

	if(flag)cout<<"yes"<<endl;
	else cout<<"no"<<endl;

	return 0;
}

