#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	bool A = false, B = false;
	for(int i = 0; i < (int) str.size(); i++){
		if(str[i]=='A')
			A = true;
		else
			B = true;
	}
	if(A && B)
		puts("Yes");
	else
		puts("No");
		
	return 0;
}