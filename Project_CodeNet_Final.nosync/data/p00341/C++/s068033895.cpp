#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void)
{
    int a[12],i;
	for(i=0;i<12;i++){
	    scanf("%d",&a[i]);
	}
	sort(a,a+12);
	if(a[0]==a[3]&&a[4]==a[7]&&a[8]==a[11]) printf("yes\n");
	else printf("no\n");
	return 0;
}