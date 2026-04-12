#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<queue>
#include<set>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int r,g,b;
int main(){
	scanf("%d%d%d",&r,&g,&b);
	if (!((g*10+b)&3)) printf("YES\n");else printf("NO\n");
	return 0;
}
