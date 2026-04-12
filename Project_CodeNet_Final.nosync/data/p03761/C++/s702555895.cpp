#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

char s[105];
int num[35], p[35], n;

int main() 
{
	while(~scanf("%d", &n)) {
		for(int i = 0; i < 26; i++) num[i] = 1000; 
		for(int i = 1; i <= n; i++) {
			scanf("%s", s);
			memset(p, 0, sizeof(p));
			int len = strlen(s);
			for(int i = 0; i < len; i++) p[s[i] - 'a']++;
			for(int i = 0; i < 26; i++) num[i] = min(num[i], p[i]);
		}
		for(int i = 0; i < 26; i++)
			for(int j = 1; j <= num[i]; j++) printf("%c", 'a' + i);
		printf("\n");
	}
}