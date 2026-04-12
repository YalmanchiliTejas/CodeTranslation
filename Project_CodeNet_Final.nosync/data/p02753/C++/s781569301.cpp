/*
	Created by Faisal Ahmed
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

int main()
{
	string str;
	
	cin >> str;
	
	int a = 0, b = 0;
	for(int i = 0; i < 3; i++){
		if(str[i] == 'A'){
			a++;
		}
		else{
			b++;
		}
	}
	
	if(a == 0 || b == 0){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
	}
	
	return 0;
}