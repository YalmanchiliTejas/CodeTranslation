#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

#define inf 0x3f3f3f3f

#define lc k << 1
#define rc k << 1 | 1

using namespace std;

typedef long long ll;

int n, k;
	char s[100005];
int main(){
	scanf("%s", s + 1);
	n = strlen (s + 1);
	for(int i = 1; i < n; i ++){
		if(s[i] == 'A' && s[i + 1] == 'C'){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}