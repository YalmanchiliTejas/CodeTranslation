#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
//1147
using namespace std;
int a,b,maxa=0,mina=10000,tot=0;
double ans;
	int main(){
		while(cin>>a){
			if(a==0){
			break;}
			for(int i=0;i<a;i++){
			cin>>b;
			tot+=b;
			if(maxa<b){maxa=b;}
			if(mina>b){mina=b;}}
			ans=(tot-maxa-mina)/(a-2);
		cout<<floor(ans)<<endl;
		tot=0;mina=10000;maxa=0;}
		return 0;}
