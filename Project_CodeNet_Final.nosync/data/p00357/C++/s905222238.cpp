#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int larger(int x, int y){
	if(x > y){
		return x;
	}
	else{
		return y;
	}
}

int main(){
	int N;
	cin >> N;
	int trampoline[N];
	for(int i = 0; i < N; i++){
		cin >> trampoline[i];
	}
	int flag = 1;
	int max = 0;
	for(int i = 0; i < N; i++){
		int jumping = 10*i + trampoline[i];
		max = larger(jumping, max);
		if(max < 10*(i+1)){
			flag = 0;
			break;
		}
	}
	max = 0;
	for(int i = 0; i < N; i++){
		int jumping = 10*i + trampoline[N-1-i];
		max = larger(jumping, max);
		if(max < 10*(i+1)){
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		cout << "yes\n";
	}
	else{
		cout << "no\n";
	}
}

