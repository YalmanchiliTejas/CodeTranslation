#include "bits/stdc++.h"
using namespace std;
string str;
int main(){
	cin >> str;
	for(int i = 0 ; i + 1 < str.size() ; ++i){
		if(str[i] == 'A' && str[i + 1] == 'C'){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}