#include<bits/stdc++.h>
#define xx first
#define yy second
#define ll long long
using namespace std;

const int N = 200000 + 5;
int a[N], n;
int stk[N], top;

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	stk[1] = 1;
	top = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] <= a[stk[top]]) {
			stk[++top] = i;
		}
		else {
			int l = 1, r = top;
			while (l < r) {
				int mid = (l + r) / 2;
				if (a[stk[mid]] < a[i]) {
					r = mid;
				}
				else {
					l = mid + 1;
				}
			}
			stk[l] = i;
		}
	}
	printf ("%d\n", top);
	return 0;
}




















