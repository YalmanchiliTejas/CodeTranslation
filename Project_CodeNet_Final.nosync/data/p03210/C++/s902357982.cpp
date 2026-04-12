#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

//  void y(void){cout << "yes"<< endl;}
  void Y(void){cout << "YES" << endl;}
  void y(void){cout << "Yes" << endl;}
//  void n(void){cout << "no"<< endl;}
  void N(void){cout << "NO" << endl;}
  void n(void){cout << "No" << endl;}
  
  
  
	int A,B,C,D,E,F,G,H,ans=0,res=0;
//	char A,B,C,D,E,F,G,H;
//	string A,B,C,D,E,F,G,H;
//	double A,B,C,D,E,F,G,H;
	
void take(int x){
	if(x==1)
		cin >> A;
	else if(x==2)
		cin >> A >> B;
	else if(x==3)
		cin >> A >> B >> C;
	else if(x==4)
		cin >> A >> B >> C >> D;
	else if(x==5)
		cin >> A >> B >> C >> D >> E;
	else if(x==6)
		cin >> A >> B >> C >> D >> E >> F;
	else if(x==7)
		cin >> A >> B >> C >> D >> E >> F >> G;
	else if(x==8)
		cin >> A >> B >> C >> D >> E >> F >> G >> H;
	return ;
}
  
int main(void){
	take(1);//数
	
	
	
	if(A==7 || A==5){
		
		
	//	y();	//Yes
		Y();	//YES
	//	n();	//No
	//	N();	//NO
	}
	
	else if(A==3){
		
		
	//	y();
		Y();
	//	n();
	//	N();
		
	}/*
	else if(){
		
		
	//	y();
	//	Y();
	//	n();
	//	N();
		
	}
	else if(){
		
		
	//	y();
	//	Y();
	//	n();
	//	N();
		
	}*/
	
	else{
		
		
	//	y();
	//	Y();
	//	n();
		N();
		
	}
//	cout << ans << endl;
	
	return 0;
}