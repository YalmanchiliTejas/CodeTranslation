#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
	string a,s("0123456789");
	int t;
	cin>>a>>t;
	int len=a.size();
	int a1[(len+1)/2];
	string a2[(len-1)/2];
	for(int i=0;i<(len+1)/2;i++){
		for(int j=0;j<10;j++){
			if(s[j]==a[2*i]){
				a1[i]=j;
				break;
			}
		}
	}
	for(int i=0;i<(len-1)/2;i++){
		a2[i]=a[2*i+1];
	}
	//L
	int lt=a1[0];
	for(int i=1;i<(len+1)/2;i++){
		if(a2[i-1]=="+"){
			lt=lt+a1[i];
		}
		else{
			lt=lt*a1[i];
		}
	}
	//M
	int mt=0;
	for(int i=0;i<(len-1)/2;i++){
		if(a2[i]=="*"){
			a1[i+1]=a1[i+1]*a1[i];
			a1[i]=0;
		}
	}
	for(int i=0;i<(len+1)/2;i++){
		mt=mt+a1[i];
	}
	if(t==mt){
		if(t==lt){
			cout<<"U"<<endl;
		}
		else{
			cout<<"M"<<endl;
		}
	}
	else{
		if(t==lt){
			cout<<"L"<<endl;
		}
		else{
			cout<<"I"<<endl;
		}
	}
    return 0;
}