#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;

	cin >> s;

	int a=(int)s.find("AC");
	if(a>=0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}