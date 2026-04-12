#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

const int N=110000;
const int M=1100000;
const LL mod=1e9+7;
int n;
char s[10];
int main()
{
   scanf("%s",s+1);
   int flag1=0,flag2=0;
   for (int i=1;i<=3;i++)
     	if (s[i]=='A') flag1=1;
        else if (s[i]='B') flag2=1;
    if (flag1&&flag2) printf("Yes\n");
    else printf("No\n");
	return 0;
}