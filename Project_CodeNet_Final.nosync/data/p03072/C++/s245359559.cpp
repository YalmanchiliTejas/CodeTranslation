#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int
int main()
{
	int a,b=0,f=0,k=0,l;
	cin>>a;
	while (a>b)
	{
		cin>>l;
		if (l>=k)
		{
			f++;
			k=l;
		}
		b++;
	}
	cout<<f;
}