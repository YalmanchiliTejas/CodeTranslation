#include<cstdio>
using namespace std;
int a[200010],b[200010];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int start = n / 2;
	int start1 = n / 2-1;
	int ch = 0;
	if (n % 2)
		ch = 1;
	b[start] = a[0];
	start++;
	for (int i = 1; i < n; i++) {
		if (ch % 2==0)
		{
			b[start1] = a[i];
			if(start)
				start1--;
		}
		else {
			b[start] = a[i];
			start++;
		}
		ch++;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
}