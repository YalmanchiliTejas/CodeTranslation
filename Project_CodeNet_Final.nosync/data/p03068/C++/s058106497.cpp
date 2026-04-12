#include<iostream>
using namespace std;

int main(){
	int n, k, i;
	cin >> n;
	char s[n+1];
	for(i=1; i<=n; i++){
		cin >> s[i];
	}
	cin >> k;
	
	for(i=1; i<=n; i++){
		if(s[i]!=s[k])	s[i] = '*';
	}
	
	for(i=1; i<=n; i++){
		cout << s[i];
	}cout << endl;
	return 0;
}
