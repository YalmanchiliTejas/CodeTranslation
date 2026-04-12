#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
	
	int d[5][2]={0};
	int max,u;
	while(cin>>d[0][0]>>d[0][1]){
	if(d[0][0]!=d[0][1]!=0){
		max=d[0][0]+d[0][1];
		u=0;
		for(int i=1;i<5;i++){
			cin>>d[i][0]>>d[i][1];
			int s=d[i][0]+d[i][1];
			if(max<s){
			max=s;
			u=i;
			}
		}
		switch(u){
		case 0: cout<<"A"<<" "<<max<<endl; break;
		case 1: cout<<"B"<<" "<<max<<endl; break;
		case 2: cout<<"C"<<" "<<max<<endl; break;
		case 3: cout<<"D"<<" "<<max<<endl; break;
		case 4: cout<<"E"<<" "<<max<<endl; break;
		}
	}
		else
			break;
		
	}
		
	
}