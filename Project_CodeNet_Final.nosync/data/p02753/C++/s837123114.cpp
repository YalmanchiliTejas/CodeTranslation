#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 300000 + 5;
int a[N];

int main(){
	string s;
	cin >> s;
	int ans1 = 0,ans2 = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A')
			ans1++;
		else if(s[i] == 'B')
			ans2++;
	}
	if(!ans1 || !ans2)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}