#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Dice(int n){
	vector<string> operation(n);
	vector<int> number(3);
	int sum = 1;
	/*for(int i=0; i<3; ++i){
		number.push_back(i+1);
	}*/
	number[0] = 1;
	number[1] = 2;
	number[2] = 3;
	//cout << number[0] << " " << number[1] << " " << number[2] << endl;
	for(int i=0; i<n; ++i){
		cin >> operation[i];
	}
	for(int i=0; i<n; ++i){
		int tmp = number[0];
		if(operation[i] == "North"){
			number[0] = number[1];
			number[1] = 7-tmp;
		}
		if(operation[i] == "East"){
			number[0] = 7-number[2];
			number[2] = tmp;
		}
		if(operation[i] == "South"){
			number[0] = 7-number[1];
			number[1] = tmp;
		}
		if(operation[i] == "West"){
			number[0] = number[2];
			number[2] = 7-tmp;
		}
		if(operation[i] == "Right"){
			int hoge = 7-number[1];
			number[1] = number[2];
			number[2] = hoge;
		}
		if(operation[i] == "Left"){
			int hoge = 7-number[2];
			number[2] = number[1];
			number[1] = hoge;
		}
		sum += number[0];
	}
	return sum;
}

int main(){
	int n;
	while(cin >> n && n){
		cout << Dice(n) << endl;
	}
	return 0;
}