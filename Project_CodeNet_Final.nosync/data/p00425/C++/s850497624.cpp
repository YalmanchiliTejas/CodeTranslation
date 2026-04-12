#include<iostream>
#include<string>
using namespace std;

void rot4(int& a,int& b,int& c,int& d){
	int tmp;
	tmp=a;
	a=b;
	b=c;
	c=d;
	d=tmp;
}

int main(){
	int n,sum,dice[6];
	string order;
	while(true){
		cin>>n;
		if(n==0)break;
		for(int i=0;i<6;i++)dice[i]=i+1;
		sum=1;
		for(int i=0;i<n;i++){
			cin>>order;
			if(order=="North"){
				rot4(dice[0],dice[1],dice[5],dice[4]);
			}else if(order=="East"){
				rot4(dice[0],dice[3],dice[5],dice[2]);
			}else if(order=="West"){
				rot4(dice[0],dice[2],dice[5],dice[3]);
			}else if(order=="South"){
				rot4(dice[0],dice[4],dice[5],dice[1]);
			}else if(order=="Right"){
				rot4(dice[1],dice[2],dice[4],dice[3]);
			}else if(order=="Left"){
				rot4(dice[1],dice[3],dice[4],dice[2]);
			}
			sum+=dice[0];
		}
		cout<<sum<<endl;
	}
	return 0;
}