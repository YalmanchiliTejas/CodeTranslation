#include <bits/stdc++.h>
using namespace std;
int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin>>s;
	bool a = false, b = false;
	for (int i=0; i<=2; i++){
		if (s[i] == 'A'){
			a = true;
		}
		else if (s[i] == 'B'){
			b = true;
		}
	}
	if (a == true && b == true){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}