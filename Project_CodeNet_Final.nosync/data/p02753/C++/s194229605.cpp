#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	string s;
	cin >> s;
	if(s[0]==s[1] && s[1]==s[2]){
		printf("No\n");
	}else{
		printf("Yes\n");
	}

	return 0;
}
