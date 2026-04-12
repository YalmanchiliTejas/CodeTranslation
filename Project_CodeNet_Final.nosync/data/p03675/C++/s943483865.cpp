#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200005],b[200005];
int main ( ) {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n%2==1) {
		for (i=n;i>=1;i-=2) printf("%d ",a[i]);
		for (i=2;i<=n;i+=2) printf("%d ",a[i]);
	}
	else {
		for (i=n;i>=2;i-=2) printf("%d ",a[i]);
		for (i=1;i<=n;i+=2) printf("%d ",a[i]);
	}
	puts("");
	return 0;
}
/*
Sample Input 1
4
1 2 3 4
Sample Output 1
4 2 1 3
Sample Input 2
3
1 2 3
Sample Output 2
3 1 2
Sample Input 3
1
1000000000
Sample Output 3
1000000000
Sample Input 4
6
0 6 7 6 7 0
Sample Output 4
0 6 6 0 7 7
*/