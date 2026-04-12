#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;

char str[maxn];
int len;

int main()
{
	scanf("%s",str); len=strlen(str);
	for(int i=0;i+1<len;i++) if(str[i]=='A'&&str[i+1]=='C') return puts("Yes"),0;
	puts("No");
	
	return 0;
}
