#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, num=0;
	int max=0;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]>=max ){num++; max=a[i];} 
		
	}
	cout << num<<endl;
	return 0;
}