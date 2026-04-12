#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int num[n],nums[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
		nums[i] = num[i];
	}
	sort(nums, nums + n);
	int me1 = nums[n / 2-1],me2=nums[n/2];
	for (size_t i = 0; i < n; i++)
	{
		if (num[i] >= me2)cout << me1 << endl;
		else cout << me2 << endl;
	}
    return 0;
}

