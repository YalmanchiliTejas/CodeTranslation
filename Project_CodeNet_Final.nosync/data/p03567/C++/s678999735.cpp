#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

#define int_inf 1000000000
#define ll_inf	100000000000000000000000

using namespace std;


int main(){
	string s;
	cin >> s;
	
	for(int i=0; i<s.size()-1; i++){
		if(s[i]=='A' && s[i+1]=='C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}
