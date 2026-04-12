#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<cmath>
#define maxn 1000007
using namespace std;
int n,m;
inline int read()
{
    int x = 0;
    int flag = 1;
    char ch;
    ch = getchar();
    while(!isdigit(ch)) 
    {
        if(ch == '-') flag = -1;
    ch = getchar();
    } 
    while(isdigit(ch))
    {
        x = (x<<1) + (x<<3) + ch - 48;
        ch = getchar();
    }
    return x * flag;
}


int main()
{
	n = read();
	m = read();
	if(n == m) printf("Yes\n");
	else printf("No\n");
}