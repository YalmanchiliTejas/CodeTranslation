#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
	int A,B,C,X,Y;
	ll ans=0;
	cin >> A >> B >> C >> X >> Y;
	if (A+B>2*C)
	{
		ans+=2*C*min(X,Y);
		if (X>Y)
		{
			if (A>C*2) ans+=C*2*(X-min(X,Y));
			else ans+=A*(X-min(X,Y));
		}
		else
		{
			if (B>C*2) ans+=C*2*(Y-min(X,Y));
			else ans+=B*(Y-min(X,Y));
		}
	}
	else
	{
		ans=A*X+B*Y;
	}
	cout << ans << endl;
	return 0;
}