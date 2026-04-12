#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int MaxN = 2e5;
using namespace std;
int a[MaxN + 5]; 
int n ;
int main()
{
	while(~scanf("%d" , &n)){
		int tot = 1;
		if(n & 1) tot++;
		for(int i = 1;i <= n;i++) scanf("%d" , &a[i]);
		for(int i = n;i >= 1;i -= 2) printf("%d " , a[i]);
		for(int i = tot;i <= n;i += 2) printf("%d " , a[i]);
		printf("\n");
	}
}