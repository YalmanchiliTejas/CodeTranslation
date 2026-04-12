#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	while(cin >> n,n){
		int s[100];

		for(int i = 0; i < n; i++)
			cin >> s[i];

		sort(s,s+n);

		int sum = 0;
		for(int i = 1; i < n-1; i++)
			sum += s[i];

		cout << sum / (n-2) << endl;
	}
	return 0;
}