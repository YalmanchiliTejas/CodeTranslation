#include <iostream>
#include <bits/stdc++.h>
using namespace std;
	bool judge(int num[], int a, int b);
	int main(void){
		int num[12];
		for(int i = 0; i < 12; i++){
			cin >> num[i];
		}
		sort(num, num + 12);
		bool a, b, c;
		a = judge(num, 0, 3);
		b = judge(num, 4, 7);
		c = judge(num, 8, 11);
		if(a && b && c){
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
		return 0;	
	}
	
	bool judge(int num[], int a, int b){
		int count = 0;
		for(int i = a + 1; i <= b; i++){
			if(num[a] == num[i]){
				count++;
			}
		}
		if(count == 3){
			return true;
		}else{
			return false;
		}
	}