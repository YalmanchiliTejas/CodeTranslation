#include <bits/stdc++.h>

int main()
{
	int n, h[25];
	scanf ("%d", &n);
	int i;
	for (i=0; i<n; i++)
		scanf ("%d", &h[i]);
	
	int j, tag;
	int num=1;
	for (i=1; i<n; i++)
	{
		tag=1;
		for (j=0; j<i; j++)
			if (h[j]>h[i]) tag=0;
		if (tag) num++;
	}
	printf("%d\n", num);
	return 0;
}