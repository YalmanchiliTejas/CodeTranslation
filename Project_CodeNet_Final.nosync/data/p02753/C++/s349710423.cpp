#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 4e5 + 7;
const double pi = acos(-1);

int main(){
	string s;
	cin >> s;
	int f1 = 0,f2 = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] == 'A') f1 = 1;
		else f2 = 1;
	}
	if(f1 && f2) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}