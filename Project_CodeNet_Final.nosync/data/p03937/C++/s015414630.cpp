#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
char s[10][10];
int main() {
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(s[i][j]=='#') ++cnt;
    int x=1,y=1;
    while(x!=n||y!=m) {
	--cnt;
	if(s[x+1][y]=='#') ++x;
	else if(s[x][y+1]=='#') ++y;
	else return puts("Impossible"),0;
    }
    puts(cnt==1?"Possible":"Impossible");
    return 0;
}