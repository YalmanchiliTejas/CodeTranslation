#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int res = 0, a =0;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (a <= tmp) {
			a = tmp;
			res++;
		}
	}
	printf("%d", res);

	return 0;
}