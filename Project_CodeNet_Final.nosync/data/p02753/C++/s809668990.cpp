#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
	int ano = 0,bno = 0;
	string inputt;
	cin>>inputt;

	for(int i =0;i<3;i++){
		if(inputt[i] == 'A'){
			ano +=1;
		}
		else{
			bno +=1;
		}
	}

	if(ano == 3 || bno ==3){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}

	return 0;
}