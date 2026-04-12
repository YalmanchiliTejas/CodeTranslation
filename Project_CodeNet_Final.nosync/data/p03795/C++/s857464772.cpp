#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
int n;
scanf("%d",&n);
int x=n/15;
int ans=n*800-x*200;
printf("%d\n",ans);
}