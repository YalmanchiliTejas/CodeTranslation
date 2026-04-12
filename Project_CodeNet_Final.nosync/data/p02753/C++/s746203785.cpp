#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int main(){
	string s;
	cin >> s;
	bool f = 0,g = 0;
	for(int i = 0;i < 3;++i){
		if(s[i] == 'A') f = 1;
		if(s[i] == 'B') g = 1;
	}
	printf("%s\n",f && g ?"Yes" :"No");
	return 0;
}
