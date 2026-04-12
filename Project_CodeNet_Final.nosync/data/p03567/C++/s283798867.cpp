#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	for(int i=0;i+1<(int)s.size();i++) {
		if (s[i]=='A'&&s[i+1]=='C') {
			printf("Yes");return 0;
		}
	}
	printf("No");return 0;
}