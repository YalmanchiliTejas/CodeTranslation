#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int x,a,b,c,i,n,p,q,y[10000],k=0;
bool sw=false;
int main(){
	while(cin>>n>>a>>b>>c>>x&&n!=0){
	p=x;q=(a*p+b)%c;
	for(int j=0;j<n;j++){
	cin>>y[j];}
		for(i=0;i<10001;i++){
			if(y[k]==p){
			k++;}
			if(k==n){
			cout<<i<<endl;sw=true;i=100000;}
		p=q;q=(a*p+b)%c;
		if(i==10000&&sw==false){
		cout<<-1<<endl;}}
    i=0;k=0;sw=false;
	}
    return 0;}
