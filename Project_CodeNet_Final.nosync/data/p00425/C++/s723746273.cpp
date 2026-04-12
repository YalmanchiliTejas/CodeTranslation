#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int top=1,bottom=6,front=2,back=5,rig=3,lef=4;

void North(){
	int alt=top;
	top=front;
	front=bottom;
	bottom=back;
	back=alt;
}

void East(){
	int alt=top;
	top=lef;
	lef=bottom;
	bottom=rig;
	rig=alt;
}

void West(){
	int alt=top;
	top=rig;
	rig=bottom;
	bottom=lef;
	lef=alt;
}

void South(){
	int alt=top;
	top=back;
	back=bottom;
	bottom=front;
	front=alt;
}

void Right(){
	int alt=front;
	front=rig;
	rig=back;
	back=lef;
	lef=alt;
}
void Left(){
	int alt=front;
	front=lef;
	lef=back;
	back=rig;
	rig=alt;
}

int main(){
	int n;
	while(1){
		cin>>n;
		if(!n)break;
		top=1;
		bottom=6;
		front=2;
		back=5;
		rig=3;
		lef=4;
		int sum=1;
		rep(i,n){
			string s;
			cin>>s;
			if(s=="North")North();
			else if(s=="South")South();
			else if(s=="East")East();
			else if(s=="West")West();
			else if(s=="Right")Right();
			else Left();
			sum+=top;			
		}
		cout<<sum<<endl;
	}
	return 0;
}