#include <iostream>
#include <string>
using namespace std;
int main(){
	while(1){
	int n; cin >> n ;if(n==0) break;
	string* way=new string[n];
	for(int i=0;i<n;i++) cin >> way[i] ;
	int dice[3]={1,2,3}; //上、手前（南）、右（東）
	int temp;int sum=1;
	for(int i=0;i<n;i++){
		if(way[i]=="North") do{temp=dice[0];dice[0]=dice[1];dice[1]=7-temp;}while(0);
		else if(way[i]=="East") do{temp=dice[2];dice[2]=dice[0];dice[0]=7-temp;}while(0);
		else if(way[i]=="West") do{temp=dice[0];dice[0]=dice[2];dice[2]=7-temp;}while(0);
		else if(way[i]=="South") do{temp=dice[1];dice[1]=dice[0];dice[0]=7-temp;}while(0);
		else if(way[i]=="Right") do{temp=dice[1];dice[1]=dice[2];dice[2]=7-temp;}while(0);
		else if(way[i]=="Left") do{temp=dice[1];dice[1]=7-dice[2];dice[2]=temp;}while(0);
		sum+=dice[0];
	};
	cout << sum << '\n' ;
	delete[] way;
	};
}