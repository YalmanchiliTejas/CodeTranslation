#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int num1 =0;
	int num2 =0;
	for(int i =0;i<s.length();i++){
		if(s[i] == 'A') num1++;
		else num2++;
	}
	if(num1 ==0 || num2 ==0) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
} 