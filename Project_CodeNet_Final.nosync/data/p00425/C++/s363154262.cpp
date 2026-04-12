#include <iostream>
#include <string>
using namespace std;

void north();
void east();
void right();


int status[6];

int main(){
	int n,m,i=0,j=0,k=0;
	int score;
	string input;
	
	
	while(j<5){
	status[0]=1;
	status[1]=2;
	status[2]=3;
	status[3]=4;
	status[4]=5;
	status[5]=6;
	score=1;
	
		cin>>n;
		if(n==0)break;
		
		for(i=0;i<n;i++){
			cin>>input;
			if(input[0]=='N'){north();}
			else if(input[0]=='S'){north();north();north();}
			else if(input[0]=='E'){east();}
			else if(input[0]=='W'){east();east();east();}
			else if(input[0]=='L'){right();}
			else if(input[0]=='R'){right();right();right();}
			score+=status[0];
			
				}
		cout<<score<<endl;
		j++;
	}
	
	return 0;
	}
	
void north(){
	swap(status[0],status[4]);
	swap(status[1],status[5]);
	swap(status[0],status[5]);
}
void east(){
	swap(status[0],status[2]);
	swap(status[5],status[3]);
	swap(status[0],status[5]);
}
void right(){
	swap(status[1],status[2]);
	swap(status[4],status[3]);
	swap(status[1],status[4]);
}

