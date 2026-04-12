#include <stdio.h>

int main()
{
	int a,b;
	scanf ("%d %d",&a,&b);
	printf ("%.12lf\n",1/(1./a+1./b));
	return 0;
}