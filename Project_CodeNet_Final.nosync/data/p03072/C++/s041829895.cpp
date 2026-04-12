//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL); 
#define endl "\n"

typedef long long int  ll;


int main()
{
	FAST;
	int n;
	cin >> n;
	int arr[n];

	for(int i=0 ; i<n ; i++)
		cin >> arr[i];

	int max1 = arr[0];
	int count = 1;
	for(int i=1 ; i<n ; i++)
	{
		if(arr[i] >= max1)
		{
			count++;
			max1 = arr[i];
		}
	}

	cout << count;
	return 0;
}