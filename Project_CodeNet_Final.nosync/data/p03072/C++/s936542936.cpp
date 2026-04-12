#include <bits/stdc++.h>

using namespace std;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	 int a,b,i,shi,ans = 1;
	 cin >> a;
	 int arr[a];

	 for (i = 0; i < a; ++i)
	 {
	 	cin >> arr[i];
	 }

	 shi = arr[0];

	 for (b = 1; b < a; ++b)
	 {
	 	if (arr[b] >= shi)
	 	{
	 		shi = arr[b];
	 		ans++;
	 	}
	 }

	 cout << ans;

    return 0;
}