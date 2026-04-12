#include <iostream>
#include <map>
using namespace std;
int x[10000];
int main() {
	
	int n;
	cin>>n;
	int MAX;
	for(int i = 0; i < n; i++)
	{
		cin>>x[i];
	}
	MAX = x[0];
	int k = 1;
	for(int i = 1; i < n; i++)
	{
		if(x[i] >= MAX)
		{
			k++;
			MAX = x[i];
		}
	}
	cout<<k;
	
	return 0;
}