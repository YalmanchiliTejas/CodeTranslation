#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int rotation(char*,string);
int main(){
	int time;
	string roll;
	while(cin>>time&&time!=0){
		int answer=0;
		char Dice[6]={1,2,3,4,5,6};
		for(int i=0;i<time;++i){
			cin>>roll;
			answer+=rotation(Dice,roll);
		}
		cout<<answer+1<<endl;
	}
	return 0;
}
int rotation(char Dice[6],string roll){
	char dommy;
	if(roll[0]=='N'){
		dommy=Dice[0];
		Dice[0]=Dice[1];
		Dice[1]=Dice[5];
		Dice[5]=Dice[4];
		Dice[4]=dommy;
	}else if(roll[0]=='E'){
		dommy=Dice[0];
		Dice[0]=Dice[3];
		Dice[3]=Dice[5];
		Dice[5]=Dice[2];
		Dice[2]=dommy;
	}else if(roll[0]=='W'){
		dommy=Dice[0];
		Dice[0]=Dice[2];
		Dice[2]=Dice[5];
		Dice[5]=Dice[3];
		Dice[3]=dommy;
	}else if(roll[0]=='S'){
		dommy=Dice[0];
		Dice[0]=Dice[4];
		Dice[4]=Dice[5];
		Dice[5]=Dice[1];
		Dice[1]=dommy;
	
	}else if(roll[0]=='R'){
		dommy=Dice[1];
		Dice[1]=Dice[2];
		Dice[2]=Dice[4];
		Dice[4]=Dice[3];
		Dice[3]=dommy;
	}else{
		dommy=Dice[1];
		Dice[1]=Dice[3];
		Dice[3]=Dice[4];
		Dice[4]=Dice[2];
		Dice[2]=dommy;
	}
	return (int)Dice[0];
}