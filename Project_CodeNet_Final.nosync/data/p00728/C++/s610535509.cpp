#include<cstdio>
#include<iostream>
using namespace std;
/*
int i_max(int data[],int size){
	int m=d[0];
	for(int i=1;i<size;i++) if(m<d[i]) m=d[i];
	return m;
}
int i_min(){
	int m=d[0];
	for(int i=1;i<size;i++) if(m>d[i]) m=d[i];
	return m;
}*/

int i_max(int p,int q){
	if(p>q) return p;
	return q;
}
int i_min(int p,int q){
	if(p<q) return p;
	return q;
}

int main(){
	int data;
	int max,min;
	int p,n;
	while(cin>>n){
		if(n==0) break;
		data=0;
		max=0;
		min=10000;
		for(int i=0;i<n;i++){
			cin>>p;
			data+=p;
			max=i_max(max,p);
			min=i_min(min,p);
		}
		data-=(max+min);
		data/=(n-2);
		cout<<data<<endl;
	}
	return 0;
}