#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int fg1=0,fg2=0;
	for(int i=0;i<3;i++){
		if(s[i]=='A')
		fg1=1;
		else
		fg2=1;
	}
	if(fg1&&fg2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
} 