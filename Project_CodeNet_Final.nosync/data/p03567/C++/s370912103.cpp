#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
int n;
const int N=100005;
char a[N];
int main ()
{
	scanf("%s",&a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]=='A'&&a[i+1]=='C'){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
