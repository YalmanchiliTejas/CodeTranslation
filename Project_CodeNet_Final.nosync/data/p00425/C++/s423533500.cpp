#include<iostream>
#include<string>

using namespace std;

	int a,b,c;
	int i,j,k,sum;
	int arr[6] = {1,2,3,4,5,6};
	


void north(){
	
	int num;
	num = arr[0];
	arr[0] = arr[1];
	arr[1] = arr[5];
	arr[5] = arr[4];
	arr[4] = num;
	sum += arr[0];
	return;
}

void south(){
	
	int num;
	num = arr[0];
	arr[0] = arr[4];
	arr[4] = arr[5];
	arr[5] = arr[1];
	arr[1] = num;
	sum += arr[0];
	return;
}

void east(){
	
	int num;
	num = arr[0];
	arr[0] = arr[3];
	arr[3] = arr[5];
	arr[5] = arr[2];
	arr[2] = num;
	sum += arr[0];
	return;
}

void west(){
	
	int num;
	num = arr[0];
	arr[0] = arr[2];
	arr[2] = arr[5];
	arr[5] = arr[3];
	arr[3] = num;
	sum += arr[0];
	return;
}

void right(){
	
	int num;
	num = arr[1];
	arr[1] = arr[2];
	arr[2] = arr[4];
	arr[4] = arr[3];
	arr[3] = num;
	sum += arr[0];
	return;
}

void left(){
	
	int num;
	num = arr[1];
	arr[1] = arr[3];
	arr[3] = arr[4];
	arr[4] = arr[2];
	arr[2] = num;
	sum += arr[0];
	return;
}



int main(){
	
	string str;
	
	
	
	while(1){
		
		sum = 1;
		for(i=0 ; i<6 ; i++) arr[i] = i+1;
		
	
		cin >> a ;
	
		if(a ==0) break;
		
		for(j = 0 ; j < a ; j++){
		
			cin >> str;
			
			if(str == "North") north();
			else if(str == "East") east();
			else if(str == "West") west();
			else if(str == "South") south();
			else if(str == "Right") right();
			else if(str == "Left") left();
		}
		
		cout << sum << endl;
		
	}
		
		
	
	return 0;
}