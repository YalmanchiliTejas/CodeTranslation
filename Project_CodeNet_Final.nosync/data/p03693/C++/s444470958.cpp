#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%s\n",(b*10+c)%4 ? "NO" : "YES");
}