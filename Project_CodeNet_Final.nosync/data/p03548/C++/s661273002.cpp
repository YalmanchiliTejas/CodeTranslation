# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
int x,y,z;

int main () {
	scanf ("%d%d%d",&x,&y,&z);
	x-=z;
	printf ("%d\n",x/(y+z));
	return 0;
}