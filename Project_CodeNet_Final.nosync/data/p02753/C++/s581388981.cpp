#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1000+10;
int main(){
	char a[4];
	cin>>a;
	int ok1=0,ok2=0;
	for(int i=0;i<3;i++){
		if(a[i]=='A'){
			ok1=1;
		}
		if(a[i]=='B'){
			ok2=1;	
		}
	}
	if(ok1&&ok2){
		cout<<"Yes";
	}
	else cout<<"No";
	return 0;
}