#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	int N;
	cin >> N;
	int H[N];
	for(int i = 0; i < N; i++){
		cin >> H[i];
	}
	int cnt = 0;
	for(int i = 0; i < N; i++){
		bool flag = true;
		for(int j = 0; j < i; j++){
			if(H[j] > H[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			cnt++;
		}
	}
	cout << cnt << "\n";
}