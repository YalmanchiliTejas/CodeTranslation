#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int i;
	string s;
	cin >> s;
	sort(s.begin(),s.end());
	if(s[0]!=s[2]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}

