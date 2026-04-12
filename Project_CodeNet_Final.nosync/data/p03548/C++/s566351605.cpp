#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<queue>
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main(){
	int x,y,z;
	int n;
	int a,b,c;
	scanf("%d %d %d",&x,&y,&z);
	n=(x-(2*z+y))/(z+y);
	printf("%d\n",n+1);
}