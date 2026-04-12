#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool f= true;
	for(int i=1;i<s.size();++i){
		if(s[i-1] == 'A' && s[i] == 'C'){
			cout << "Yes" << endl;
			f = false;
			break;
		} 
	}
	
	if(f) cout << "No" << endl;

	
	return 0;


}

