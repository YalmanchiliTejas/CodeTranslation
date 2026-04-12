#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n[12]={0},i;
	for(i=0;i<12;i++){
		cin>>n[i];
	}
	sort(n,n+12);
	if(n[0]==n[1]&&n[0]==n[2]&&n[0]==n[3]){
		if(n[4]==n[5]&&n[4]==n[6]&&n[4]==n[7]){
			if(n[8]==n[9]&&n[8]==n[10]&&n[8]==n[11]){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		}else{
			cout<<"no"<<endl;
		}
	}else{
		cout<<"no"<<endl;
	}
	return 0;
}