#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i=0;i<n;i++)
		cin >> h[i];
	
	int mx=0,count=0;
	for(int i=0;i<n;i++)
		if(mx<=h[i])
		{
			count++;
			mx=h[i];
		}

	cout << count << endl;
}