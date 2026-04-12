#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char c[10050];
int main(){
	cin>>c+1;
	int f=0;
	for(int i=1;i<=strlen(c+1);i++){
		if(f&&c[i]=='C'){
			cout<<"Yes"<<endl;
			return 0;
		}
		if(c[i]=='A')f=1;else f=0;
	}
	cout<<"No"<<endl;
}