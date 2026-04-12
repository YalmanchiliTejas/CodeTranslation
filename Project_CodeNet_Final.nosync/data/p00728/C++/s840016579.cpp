#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int s[101];
	int sum;
	
	while(scanf("%d", &n), n != 0){
		sum = 0;
		for (int i = 0; i < n;i++) scanf("%d", &s[i]);
		
		sort(s, s + n);
		
		for (int i = 1; i < n-1; i++){
			sum += s[i];
		}
		
		printf("%d\n", sum/(n-2));
	}
}