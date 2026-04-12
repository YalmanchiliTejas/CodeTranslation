#include<bits/stdc++.h>

using namespace std;

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	int a,b,c,x,y;

	cin >> a >> b >> c >> x >> y;

	int onlyC, AandB, other;
	int answer;

	AandB = a*x + b*y;
	onlyC = 2*c*max(x,y);
	if (x>y)
	{
		other = 2*c*(y) + a*(x-y);
	}
	else
	{
		other = 2*c*(x) + b*(y-x);
	}
	answer = min(onlyC,min(AandB,other));
	cout << answer;


	return 0;
}