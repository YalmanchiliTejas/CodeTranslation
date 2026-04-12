#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int a,b,c,x,y;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c >> x >> y;

	int n = max(x,y);

	int res = a*x+b*y;

	for(int i=1;i<=n;i++)
	{
		int cal = c*(2*i);
		if(x-i>0)
		{
			cal += (x-i)*a;
		}
		if(y-i>0)
		{
			cal += (y-i)*b;
		}
		res = min(res,cal);
	}

	cout << res << '\n';
	return 0;
}