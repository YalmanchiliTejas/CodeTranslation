# include <iostream>
# include <cstdio>

using namespace std;
 
int x, y, z, ans;

int main()
{
	scanf("%d %d %d", &x, &y, &z);
	
	ans = (x - z) / (y + z);
	
	printf("%d\n", ans);
			
	return 0;
} 