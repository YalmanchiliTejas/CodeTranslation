#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <math.h>
using namespace std;
int main(){

	int N, K;
	string S;
	cin >> N >> S >> K;
	string str[N];
	for(int i = 0; i < N; i++){
		str[i] = S.substr(i,1);
	}
	for(int j = 0; j < N; j++){
		if(str[j] != str[K-1]){
			str[j] = "*";
		}
	}
	for(int m = 0; m < N; m++){
		cout << str[m];
	}
	cout << endl;

}