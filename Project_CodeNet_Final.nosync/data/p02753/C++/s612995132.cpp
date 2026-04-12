#include <bits/stdc++.h>
#include <iostream>
#define M 101

using namespace std;

int main(){
	string ts;
	cin >> ts;
	int acount=0;
	int bcount = 0;
	for (int i = 0; i<ts.length(); i++){
		if (ts[i] == 'A'){
			acount++; 
		} else {
			bcount++;
		}
	}
	if (bcount != 3 && acount != 3){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
			
		
