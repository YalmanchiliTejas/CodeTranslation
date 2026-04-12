#include<iostream>


using namespace std;

int main(){
	
	char S[3];
	int A = 0;
	int B = 0;
	
	for(int i = 0; i < 3; i++){
		cin>>S[i];
		
		if(S[i] == 'A'){
			A++;
			
		}else{
			B++;
			
		}
	}
	
	if(A == 2 || B == 2){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	
	
	return 0;
}