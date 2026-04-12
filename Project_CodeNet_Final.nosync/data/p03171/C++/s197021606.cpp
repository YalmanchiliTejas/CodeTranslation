#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>
#include<stack>
#include<queue>
#include<math.h>


using namespace std;
long long int grr[3005][3005] ;

long long int compute(long long int arr[], long long int start, long long int end)
{	if (grr[start][end] != 0)
		return grr[start][end];
	if (start > end)
		return 0;
	if (start == end) {
		grr[start][end] = arr[start];
		return grr[start][end];
	}

	grr[start][end] = max(arr[start] + min(compute(arr, start + 2, end), compute(arr, start + 1, end - 1)),
	                      arr[end] + min(compute(arr, start, end - 2), compute(arr, start + 1, end - 1)));
	return grr[start][end];
}




int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n;
	cin >> n;
	long long int arr[n];
	long long int a = 0, b = 0;
	for (long long int i = 0; i < n; i++)
	{
		cin >> arr[i];
		b += arr[i];
	}
	a = compute(arr, 0, n - 1);

	cout << a - (b - a) << endl;

	return 0;


}
