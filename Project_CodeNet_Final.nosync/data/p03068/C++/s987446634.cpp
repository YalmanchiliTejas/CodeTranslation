#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define ll long long
char a[200];
int n,k;
int main(){
	cin>>n>>a>>k;
	char x=a[k-1];
	for(int i=0;i<strlen(a);i++){
		if(a[i]!=x){
			cout<<"*";
		}
		else cout<<a[i];
	}
	return 0;
}