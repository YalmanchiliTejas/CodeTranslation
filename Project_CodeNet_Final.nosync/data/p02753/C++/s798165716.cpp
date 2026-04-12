#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	string s;
	cin >> s;
	int acnt = 0,bcnt = 0;
	for(int i = 0;i < 3;i++){
		if(s[i] == 'A'){
			acnt++;
		}else{
			bcnt++;
		}
	}
	if(acnt == 0 || bcnt == 0){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
}