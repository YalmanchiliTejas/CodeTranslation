#include <iostream>
using namespace std;

int main(){
	int n, k;
	string s;
	char c;
	cin >> n >> s >> k;
	c = s[k-1];
	for(int i=0; i<s.length(); i++){
		if(s[i]!=c){
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}