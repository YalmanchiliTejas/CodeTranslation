#if 1

#include<bits/stdc++.h>
using namespace std;
long long a[3001];
long long d[3001];
int main()
{
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
    }
	for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j+i-1 <= n;j++)
        {
            d[j] = max(a[j]-d[j+1],a[j+i-1]-d[j]);
        }
    }
	cout << d[1];
}

#endif // 1++