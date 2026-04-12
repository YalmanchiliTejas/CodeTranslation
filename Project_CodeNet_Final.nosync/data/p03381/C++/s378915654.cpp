#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int maxn = 2e5 + 500;
int a[maxn],b[maxn];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1);
	int mid = n / 2;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] <=a[mid])
			cout << a[mid+1] << endl;
		else if(b[i]>a[mid])
			cout << a[mid]<< endl;
	}
	return 0;
}