#include <stdio.h>
#include <algorithm>
using namespace std;
using ll = long long;

char s[10];
int main() {
	scanf("%s", s);
	printf(s[0] != s[1] || s[1] != s[2] ? "Yes\n" : "No\n");
}