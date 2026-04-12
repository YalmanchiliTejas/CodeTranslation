#include <iostream>

# define REP(i,n) for(int i=0; i<n;i++)

using namespace std;

int main(){
	
	string s;
	cin >> s;
	
	REP(i,s.length()){
		if (s[i]=='A' && i<s.length()-1){
			if (s[i+1]=='C'){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	
	cout << "No" << endl;
}
