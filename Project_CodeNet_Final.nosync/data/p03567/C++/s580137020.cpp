#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a, b, n;
	string s;
	cin >> s;
	for(int i = 0; i < s.size() - 1; ++i){
		if(s[i] == 'A' && s[i + 1] == 'C'){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}