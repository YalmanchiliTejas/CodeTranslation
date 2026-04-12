#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<cstring>
using namespace std;
int maxim(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
int tanri(double a,int y,double ri,double te){
	double i,b=0;
	for(i=0;i<y;i++){
		b+=a*ri;
		a-=te;
		a=(int)a;
		b=(int)b;
	}
	return a+b;
}

int fukuri(double a,int y,double ri,double te){
	int i,j;
	for(i=0;i<y;i++){
		a+=a*ri;
		a-=te;
		a=(int)a;
	}
	return a;
}

int main(){
	int m;
	cin>>m;
	for(;m>0;m--){
		int i,j,k,year,n,th;
		double a,b,c,max,ri,te;
		cin>>a>>year>>n;
		max=a;
		for(i=0;i<n;i++){
			cin>>th>>ri>>te;
			if(th==0){
				max=maxim((int)max,tanri(a,year,ri,te));
			}else{
				max=maxim((int)max,fukuri(a,year,ri,te));
			}
		}
		cout<<(int)max<<endl;
	}
    return 0;
}