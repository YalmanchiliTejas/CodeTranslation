#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b,c,d,s,w;
int main()
{
	scanf("%d %d %d",&a,&b,&c);
	
	s=a-c;
	d=0;
	w=s/(b+c);
		printf("%d\n",w);
	
}