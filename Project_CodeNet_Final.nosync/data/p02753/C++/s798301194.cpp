#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long LL;

int main() {
	string s;
	cin >> s;
	int l1 = s.length();
	for (int i = 0; i < l1 - 1; i++) {
		if (s[i] != s[i + 1]) {
			printf("Yes\n");
			return 0;
		}
	}	
	printf("No\n");
}