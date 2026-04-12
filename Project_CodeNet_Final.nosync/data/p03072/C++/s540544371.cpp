#include <bits/stdc++.h>
using namespace std;
int n;
int h[21];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
    	cin >> h[i];
	}
    bool f=0;
    int op=1;
	for(int i=2;i<=n;i++)
	{
		f=1;
		for(int j=1;j<=i;j++)
		{
			if(h[i]<h[j])
			f=0;
		}
		if(f) op++;
	}
	cout << op << endl;
    return 0;
}