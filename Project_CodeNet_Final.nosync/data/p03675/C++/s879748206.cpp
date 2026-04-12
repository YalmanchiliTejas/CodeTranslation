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
int n,a[300000];
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	for(int i=n;i>0;i-=2) printf("%d ",a[i]);//i
	for(int i=(n&1)?2:1;i<=n;i+=2) printf("%d ",a[i]);
	return 0;
}