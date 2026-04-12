#include<iostream>
using namespace std;

int h[20],c[20];
int main()

{	
	int n,b=0,max;
	cin >> n;
	for (int i=0;i<n;i++)
		cin >>h[i];
		
	max=h[0];
	
	for (int i=0;i<n;i++)
	{
		if (h[i]>=max)
		{ b++;
		  max=h[i];	}
	}
	cout << b;
}
