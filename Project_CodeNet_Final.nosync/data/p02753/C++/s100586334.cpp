#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define mp make_pair
 
using namespace std;

typedef long long ll;

int main(){
	int n;

	char s[5];
	scanf(" %s", s);

	if(s[0] == s[1] && s[1] == s[2]) printf("No\n");
	else printf("Yes\n");

	return 0;
}