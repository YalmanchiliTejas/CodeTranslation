#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[12];
	int i,j;
	int cut=0;
	int b[3]={1,5,9};
	for(i=0;i<12;i++){
		cin>>a[i];
	}
	for(i=0;i<12;i++){
		for(j=11;j>i;j--){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	//cout<<"a"<<endl;
	for(i=0;i<3;i++){
		for(j=b[i];j<=b[i]+2;j++){
			if(a[b[i]-1]==a[j]){
				cut++;
			}
		}
	}
	if(cut==9){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
	return 0;
}