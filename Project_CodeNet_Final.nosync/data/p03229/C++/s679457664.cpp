#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n;
	long long a[100005];
	long long sum1 = 0,sum2 = 0;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int l = 1,r = n;
	sort(a + 1, a + n + 1);
	sum1 = abs(a[l] - a[r]);
	sum2 = abs(a[l] - a[r]);
		if(n % 2 == 0){
			for(int i = 2;i <= (n+1)/2;i++){
				sum1 += abs(a[l] - a[n - i + 1]);
				sum1 += abs(a[r] - a[i]);
				l++;
				r--;
			}
		}else{
			l = 1,r = n;
			long long x = a[(n+1)/2];
			for(int i = 2;i < (n+1)/2;i++){
				sum2 += abs(a[r] - a[i]);
				sum2 += abs(a[l] - a[n - i + 1]);
				l++;
				r--;
			}
			sum2 += max(abs(x - a[(n+1)/2 + 1]) , abs(x - a[(n+1)/2 - 1]));
		}
	cout << max(sum1,sum2) << endl;
	return 0;
}