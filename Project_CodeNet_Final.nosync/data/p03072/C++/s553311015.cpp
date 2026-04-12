#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n";

int main()
{
	int n, last = 0, a, coun = 0;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a ;
		
		if(a >= last)
		{
			coun++;
			last = a;
		}
	}
	
	cout << coun << endl;
	
	return 0;
}
