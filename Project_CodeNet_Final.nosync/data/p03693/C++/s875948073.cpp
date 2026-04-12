#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc , char **argv)
{
	(void)argc;
	(void)argv;

	int r,g,b;
	cin >> r >> g >> b;
	int A = r *100 + g*10 + b;
	if (A%4==0){printf("YES\n");}else{printf("NO\n");}

	return 0;
}