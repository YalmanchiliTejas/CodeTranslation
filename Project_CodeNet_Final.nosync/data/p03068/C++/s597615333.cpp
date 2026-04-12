#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin >> a;
	string n;
	cin >> n;
	cin >> b;
	for(int i = 0;i<a;i++){
		if(n[i] == n[b-1]){
			cout << n[i];
		}
		else{
			cout << "*";
		}
	}
	return 0;
} 