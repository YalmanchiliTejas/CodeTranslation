#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<set>
using namespace std;
typedef uint64_t ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
ll N, m;
int main() {
	char str[4];
	bool flag = true;
	scanf("%s", str);
	rep(i, 1, 3)flag &= str[i] == str[0];
	printf(flag?"No":"Yes");
	return 0;
}