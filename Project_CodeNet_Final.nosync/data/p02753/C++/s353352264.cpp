#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);             
	bool a = false, b = false;
	char ch;
	while(cin >> ch){
		if(ch == 'A')	a = true;
		else if (ch == 'B') b = true;
	}	
	if(a && b)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;    	
}