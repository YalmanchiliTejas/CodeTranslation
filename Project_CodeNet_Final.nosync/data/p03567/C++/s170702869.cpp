#include<map>
#include<cmath>
#include<stack>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[1005];
int main(){
	scanf("%s",s);
	if(strstr(s,"AC")-s>=0)puts("Yes");
	else puts("No");
	return 0;
}