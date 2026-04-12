#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;

int a[200005];
int p[200005];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int l = n;
	int r = n;
	int qz = 2;
	int qy = n;
	int tot = 0;
	p[n] = a[1];
	while(r - l + 1 < n)
	{
		tot++;
		if(tot % 2 == 1) {
			if(a[l] >= a[r]) {
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qy];
					qy--;
				}
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qy];
					qy--;
				}
			}
			else {
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qy];
					qy--;
				}
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qy];
					qy--;
				}
			}
		}
		else {
			if(a[l] <= a[r]) {
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qz];
					qz++;
				}
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qz];
					qz++;
				}
			}
			else {
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qz];
					qz++;
				}
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qz];
					qz++;
				}
			}
		}
	}
	int fl = 0;
	LL sum = 0;
	for(int i = 1; i <= 2 * n; i++)
	{
		if(p[i + 1] == 0 && fl == 1) break;
		if(p[i] != 0) fl = 1;
		if(fl == 1) sum = sum + (LL)abs(p[i] - p[i + 1]);
	}
	for(int i = 1; i <= 2 * n; i++) p[i] = 0;
	l = n;
	r = n;
	qz = 1;
	qy = n - 1;
	tot = 0;
	p[n] = a[n];
	while(r - l + 1 < n)
	{
		tot++;
		if(tot % 2 == 0) {
			if(a[l] >= a[r]) {
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qy];
					qy--;
				}
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qy];
					qy--;
				}
			}
			else {
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qy];
					qy--;
				}
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qy];
					qy--;
				}
			}
		}
		else {
			if(a[l] <= a[r]) {
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qz];
					qz++;
				}
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qz];
					qz++;
				}
			}
			else {
				if(r - l + 1 < n && qy >= qz) {
					l--;
					p[l] = a[qz];
					qz++;
				}
				if(r - l + 1 < n && qy >= qz) {
					r++;
					p[r] = a[qz];
					qz++;
				}
			}
		}
	}
	fl = 0;
	LL su1 = 0;
	for(int i = 1; i <= 2 * n; i++)
	{
		if(p[i + 1] == 0 && fl == 1) break;
		if(p[i] != 0) fl = 1;
		if(fl == 1) su1 = su1 + (LL)abs(p[i] - p[i + 1]);
	}
	printf("%lld\n", max(su1, sum));
}