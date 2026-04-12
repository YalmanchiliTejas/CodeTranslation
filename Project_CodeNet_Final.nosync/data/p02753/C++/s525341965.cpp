#include<iostream>
#include<string.h>

using namespace std;

int main(){
	char kata[10];
	cin >> kata;
	if(kata[0] == kata[1] && kata[0] == kata[2] && kata[1] == kata[2]){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
	return 0;
}
