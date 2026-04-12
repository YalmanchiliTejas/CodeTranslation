#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	
	int x;
	cin >> x;
	
	switch(x){
		case 3:
		case 5:
		case 7:
			puts("YES");
			break;
		default:
			puts("NO");
			break;
	}
	
	return 0;
}