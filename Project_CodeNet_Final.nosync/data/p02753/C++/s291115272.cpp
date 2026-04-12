#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back

string s;

int main(){
	
	cin >> s;
	for ( int i = 1; i < 3; i++ ){
		if ( s[i] != s[i-1] ){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}